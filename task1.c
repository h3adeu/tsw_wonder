#include "task1.h"
#include "task2.h"
#include "main.h"
#include <stdio.h>

// タスク1のコンテキスト
context_t task1_context;

// タスク1の開始関数
void task1_start(void) {

  // '*' を順に増やしながら10回表示する
  for (int i = 0; i < 10; i++) {
    // タスク名を表示
    printf("task1:(%02d) ", i);

    // '=' をインデクス分表示
    for (int j = 0; j <= i; j++) {
       printf("=");
    }

    // 改行
    printf("\n");

    // タスク2にコンテキストを切り替える
    context_switch(&task1_context, &task2_context);
  }

  // メインにコンテキストを切り替える
  context_switch(&task1_context, &main_context);
}

// タスク1のスタック・サイズ(ワード単位)
#define STACK_SIZE (16 * 1024)

// タスク1の初期化
void task1_context_init() {
  context_init(&task1_context, STACK_SIZE, task1_start);
}
