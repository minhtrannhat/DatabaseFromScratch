/* code does not compile with gcc or mingw, only clang (on Unix systems) is supported */
#pragma once

#include </usr/lib/clang/10.0.1/include/stddef.h>
#include </usr/include/sys/types.h>

// store user input in a buffer
typedef struct {
  char *buffer;           // store the read line read by getline()
  size_t buffer_length;   // size of the allocated buffer
  ssize_t input_length;   // store the return value (the number of bytes read)
} InputBuffer;
