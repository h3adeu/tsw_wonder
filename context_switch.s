//////////////////////////////////////////////////////////////////////////////
//
// void context_switch(context_t* old, context_t* new)
//
// old に古いコンテキスト
// new に新しいコンテキスト
//
//   rsp => +0x00: (r15)
//          +0x04: (r14)
//          +0x08: (r12)
//          +0x0c: (r11)
//          +0x10: (r10)
//          +0x14: (r9)
//          +0x18: (r8)
//          +0x1c: (rdi)
//          +0x20: (rsi)
//          +0x24: (rbp)
//          +0x28: (rdx)
//          +0x2c: (rcx)
//          +0x30: (rbx)
//          +0x34: (rax)
//          +0x38: (rflags)
//          +0x3c: (rip)         // 戻り番地
//
// この実装は説明の為に OS(POSIX) 上のアプリケーション層でのコンテキストに限定
// してシンプルな作りにしています。
//
// 組込機器などの OS を持っていない機器で作る場合は、セグメントやCPUの状態
// などもコンテキストとして保存、復元が必要です。仮想記憶やファイルI/O等も
// サポートする場合も同様にタスク毎に切り替わる物はコンテキストに追加する
// 必要があります。(この例では説明をシンプルにする為に汎用レジスタのみを対
// 象にしています。その為に浮動小数点レジスタ、セグメント・レジスタも保存/
// 復元していません)
//////////////////////////////////////////////////////////////////////////////
  .globl context_switch

context_switch:

  // コンテキストを保存
  pushfq
  pushq %rax
  pushq %rbx
  pushq %rcx
  pushq %rdx
  pushq %rbp
  pushq %rsi
  pushq %rdi
  pushq %r8
  pushq %r9
  pushq %r10
  pushq %r11
  pushq %r12
  pushq %r13
  pushq %r14
  pushq %r15

  // 現在のスタック・ポインタを old_esp が指す古いスタック・ポインタの保存先にセット
  movq %rsp,(%rdi)

load_new_context:

  // new_sp が指す新しいスタック・ポインタから切替先のスタック・ポインタを得てスタック・ポインタにセット
  movq (%rsi),%rsp

  // コンテキストを復元
  popq %r15
  popq %r14
  popq %r13
  popq %r12
  popq %r11
  popq %r10
  popq %r9
  popq %r8
  popq %rdi
  popq %rsi
  popq %rbp
  popq %rdx
  popq %rcx
  popq %rbx
  popq %rax
  popfq

  // 新しいコンテキストで復帰(別のタスクに切り替え)
  retq

  .end
