#include <stdint.h>
#include "context.h"

// コンテキストを初期化する
extern void context_init(context_t *out_context,
                         uint64_t *in_stack,
                         size_t in_size,
                         task_t in_start) {
  // スタック・ポインタを定義
  uint64_t* sp = &in_stack[in_size - 1];

  // スタック中のコンテキストをセットアップする
  *--sp = (uint64_t)in_start;
  *--sp = (uint64_t)0;          /* flags */
  *--sp = (uint64_t)0;          /* rax*/
  *--sp = (uint64_t)0;          /* rbx */
  *--sp = (uint64_t)0;          /* rcx */
  *--sp = (uint64_t)0;          /* rdx */
  *--sp = (uint64_t)0;          /* rbp */
  *--sp = (uint64_t)0;          /* rsi */
  *--sp = (uint64_t)0;          /* rdi */
  *--sp = (uint64_t)0;          /* r15 */
  *--sp = (uint64_t)0;          /* r14 */
  *--sp = (uint64_t)0;          /* r13 */
  *--sp = (uint64_t)0;          /* r12 */
  *--sp = (uint64_t)0;          /* r11 */
  *--sp = (uint64_t)0;          /* r10 */
  *--sp = (uint64_t)0;          /* r9 */
  *--sp = (uint64_t)0;          /* r8 */
  *--sp = (uint64_t)0;          /* XMM0(下位) */
  *--sp = (uint64_t)0;          /* XMM0(上位) */
  *--sp = (uint64_t)0;          /* XMM1(下位) */
  *--sp = (uint64_t)0;          /* XMM1(上位) */
  *--sp = (uint64_t)0;          /* XMM2(下位) */
  *--sp = (uint64_t)0;          /* XMM2(上位) */
  *--sp = (uint64_t)0;          /* XMM3(下位) */
  *--sp = (uint64_t)0;          /* XMM3(上位) */
  *--sp = (uint64_t)0;          /* XMM4(下位) */
  *--sp = (uint64_t)0;          /* XMM4(上位) */
  *--sp = (uint64_t)0;          /* XMM5(下位) */
  *--sp = (uint64_t)0;          /* XMM5(上位) */
  *--sp = (uint64_t)0;          /* XMM6(下位) */
  *--sp = (uint64_t)0;          /* XMM6(上位) */
  *--sp = (uint64_t)0;          /* XMM7(下位) */
  *--sp = (uint64_t)0;          /* XMM7(上位) */
  *--sp = (uint64_t)0;          /* XMM8(下位) */
  *--sp = (uint64_t)0;          /* XMM8(上位) */
  *--sp = (uint64_t)0;          /* XMM9(下位) */
  *--sp = (uint64_t)0;          /* XMM9(上位) */
  *--sp = (uint64_t)0;          /* XMM10(下位) */
  *--sp = (uint64_t)0;          /* XMM10(上位) */
  *--sp = (uint64_t)0;          /* XMM11(下位) */
  *--sp = (uint64_t)0;          /* XMM11(上位) */
  *--sp = (uint64_t)0;          /* XMM12(下位) */
  *--sp = (uint64_t)0;          /* XMM12(上位) */
  *--sp = (uint64_t)0;          /* XMM13(下位) */
  *--sp = (uint64_t)0;          /* XMM13(上位) */
  *--sp = (uint64_t)0;          /* XMM14(下位) */
  *--sp = (uint64_t)0;          /* XMM14(上位) */
  *--sp = (uint64_t)0;          /* XMM15(下位) */
  *--sp = (uint64_t)0;          /* XMM15(上位) */

  // コンテキストのスタック・ポインタを初期化
  out_context->sp = sp;
}
