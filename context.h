#ifndef CONTEXT_H
#define CONTEXT_H

#include <stdlib.h>
#include <stdint.h>

// コンテキスト型
typedef struct {
  uint64_t* sp;  // スタック・ポインタ
} context_t;

// タスクの開始関数
typedef void (*task_t)(void);

// コンテキスト型に対する操作
extern void context_init(context_t* io_context, size_t in_size, task_t in_start); 
extern void context_switch(context_t* out_ontext, context_t* in_context);

#endif
