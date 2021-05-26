#ifndef MAIN_H
#define MAIN_H

#include "context.h"

// メインのコンテキスト
extern context_t main_context;

// 出力関数
ssize_t _write(int fd, const void* buf, size_t count);

#endif
