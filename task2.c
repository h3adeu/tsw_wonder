#include "task2.h"
#include "task1.h"
#include "main.h"
#include <stdio.h>

// タスク2のコンテキスト
context_t task2_context;

// タスク2の開始関数
void task2_start(void) {

  // '*' を順に減らしながら10回表示する
  for (int i = 9; i >= 0; i--) {
    // タスク名を表示
    printf("task2:(%02d) ", i);

    // '=' をインデックス分表示
    for (int j = 0; j <= i; j++) {
       printf("=");
    }

    // 改行
    printf("\n");

    // タスク1にコンテキストを切り替える
    context_switch(&task2_context, &task1_context);
  }

  // メインにコンテキストを切り替える
  context_switch(&task1_context, &main_context);
}

// タスク2のスタック・サイズ(ワード単位)
#define STACK_SIZE (16 * 1024)

// タスク2の初期化
void task2_context_init() {
  context_init(&task2_context, STACK_SIZE, task2_start);
}
