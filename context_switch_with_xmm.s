//////////////////////////////////////////////////////////////////////////////
//
// void context_switch(uint32* old_sp, uint32_t* new_sp)
//
// old_sp に構築されるスタック・フレーム、または
// new_sp に構築されているスタック・フレームは以下の通り
//
//   esp => +00: (ebx)
//          +04: (ecx)
//          +08: (edx)
//          +12: (esi)
//          +16: (edi)
//          +20: (eax)
//          +24: (ebp)

//          +28: (rip)         // 以下は戻り番地と関数の引数
//
// この実装は説明の為に OS(POSIX) 上のアプリケーション層でのコンテキストに限定
// してシンプルな作りにしています。
//
// 組込機器などの OS を持っていない機器で作る場合は、セグメントやCPUの状態
// などもコンテキストとして保存、復元が必要です。仮想記憶やファイルI/O等も
// サポートする場合も同様にタスク毎に切り替わる物はコンテキストに追加する
// 必要があります。
//////////////////////////////////////////////////////////////////////////////
  .globl context_switch

OLD_SP = 32
NEW_SP = 36

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
  subq $0x10,%rsp
  movdqu %xmm0,(%rsp)
  subq $0x10,%rsp
  movdqu %xmm1,(%rsp)
  subq $0x10,%rsp
  movdqu %xmm2,(%rsp)
  subq $0x10,%rsp
  movdqu %xmm3,(%rsp)
  subq $0x10,%rsp
  movdqu %xmm4,(%rsp)
  subq $0x10,%rsp
  movdqu %xmm5,(%rsp)
  subq $0x10,%rsp
  movdqu %xmm6,(%rsp)
  subq $0x10,%rsp
  movdqu %xmm7,(%rsp)
  subq $0x10,%rsp
  movdqu %xmm8,(%rsp)
  subq $0x10,%rsp
  movdqu %xmm9,(%rsp)
  subq $0x10,%rsp
  movdqu %xmm10,(%rsp)
  subq $0x10,%rsp
  movdqu %xmm11,(%rsp)
  subq $0x10,%rsp
  movdqu %xmm12,(%rsp)
  subq $0x10,%rsp
  movdqu %xmm13,(%rsp)
  subq $0x10,%rsp
  movdqu %xmm14,(%rsp)
  subq $0x10,%rsp
  movdqu %xmm15,(%rsp)

  // 現在のスタック・ポインタを old_esp が指す古いスタック・ポインタの保存先にセット
  movq %rsp,(%rdi)

load_new_context:

  // new_sp が指す新しいスタック・ポインタから切替先のスタック・ポインタを得てスタック・ポインタにセット
  movq (%rsi),%rsp

  // コンテキストを復元
  movdqu (%rsp), %xmm15
  addq $0x10,%rsp
  movdqu (%rsp), %xmm14
  addq $0x10,%rsp
  movdqu (%rsp), %xmm13
  addq $0x10,%rsp
  movdqu (%rsp), %xmm12
  addq $0x10,%rsp
  movdqu (%rsp), %xmm11
  addq $0x10,%rsp
  movdqu (%rsp), %xmm10
  addq $0x10,%rsp
  movdqu (%rsp), %xmm9
  addq $0x10,%rsp
  movdqu (%rsp), %xmm8
  addq $0x10,%rsp
  movdqu (%rsp), %xmm7
  addq $0x10,%rsp
  movdqu (%rsp), %xmm6
  addq $0x10,%rsp
  movdqu (%rsp), %xmm5
  addq $0x10,%rsp
  movdqu (%rsp), %xmm4
  addq $0x10,%rsp
  movdqu (%rsp), %xmm3
  addq $0x10,%rsp
  movdqu (%rsp), %xmm2
  addq $0x10,%rsp
  movdqu (%rsp), %xmm1
  addq $0x10,%rsp
  movdqu (%rsp), %xmm0
  addq $0x10,%rsp
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
