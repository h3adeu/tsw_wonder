#include "task1.h"
#include "task2.h"
#include "context.h"

context_t main_context;

int main(int argc, char **argv) {

  // タスク1のコンテキストを初期化
  task1_context_init();

  // タスク2のコンテキストを初期化
  task2_context_init();

  // タスク1にコンテキストを切り替える
  context_switch(&main_context, &task1_context);
}
