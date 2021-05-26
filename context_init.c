#include <stdint.h>
#include <stdlib.h>
#include "context.h"

// コンテキストを初期化する
extern void context_init(context_t *out_context,
                         size_t in_size,
                         task_t in_start) {
  // スタック・ポインタを定義
  uint64_t* stack = (uint64_t*)malloc(in_size * sizeof(uint64_t));
  uint64_t* sp = &stack[in_size - 1];

  // スタック中のコンテキストをセットアップする
  // (動作を分かり易くする為に全てのレジスタに判別し易い値をセットいておきます)
  *--sp = (uint64_t)in_start;
  *--sp = (uint64_t)0;          /* flags */
  *--sp = (uint64_t)1;          /* rax*/
  *--sp = (uint64_t)2;          /* rbx */
  *--sp = (uint64_t)3;          /* rcx */
  *--sp = (uint64_t)4;          /* rdx */
  *--sp = (uint64_t)5;          /* rbp */
  *--sp = (uint64_t)6;          /* rsi */
  *--sp = (uint64_t)7;          /* rdi */
  *--sp = (uint64_t)8;          /* r8 */
  *--sp = (uint64_t)10;         /* r9 */
  *--sp = (uint64_t)11;         /* r10 */
  *--sp = (uint64_t)12;         /* r11 */
  *--sp = (uint64_t)13;         /* r12 */
  *--sp = (uint64_t)14;         /* r13 */
  *--sp = (uint64_t)15;         /* r14 */
  *--sp = (uint64_t)16;         /* r15 */

  // (この例では説明をシンプルにする為に汎用レジスタのみを対象にしています。
  // その為に浮動小数点レジスタ、セグメント・レジスタも設定していません)
   
  // コンテキストのスタック・ポインタを初期化
  out_context->sp = sp;
}
