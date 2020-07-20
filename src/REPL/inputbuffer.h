/* size_t and ssize_t are only available on POSIX system
 * so this header is included
 */
#include <sys/types.h>

// for size_t and ssize_t
#include <stdlib.h>

// store user input in a buffer
typedef struct {
  char *buffer;           // store the read line read by getline()
  size_t buffer_length;   // size of the allocated buffer
  ssize_t input_length;   // store the return value (the number of bytes read)
} InputBuffer;
