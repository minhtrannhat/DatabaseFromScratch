#include "../SQL_Compiler/sql_compiler.c"

#define NULL 0

InputBuffer *new_input_buffer() {
  InputBuffer *input_buffer = (InputBuffer *)malloc(sizeof(InputBuffer));

  // store the read line read by getline()
  input_buffer->buffer = NULL;

  // size of the allocated buffer
  input_buffer->buffer_length = 0;

  // store the return value (the number of bytes read)
  input_buffer->input_length = 0;

  return input_buffer;
}

// print a line to the user
void print_prompt() { printf("db > "); }

/* lineptf: a pointer to the variable we use to point to the buffer containing
 * the read line. If it sets to Null it is mallocated by getLine and should be
 * freed by the user, even if the comment fails.
 *
 * n: a pointer to the variable we use to save the size of allocated buffer
 *
 * stream: the input stream to read from.
 *
 * return value: the number of bytes read, which maybe less than the size of the
 * buffer.
 */

// read a line of input
ssize_t getline(char **lineptr, size_t *n, FILE *stream);

void read_input(InputBuffer *input_buffer) {
  ssize_t bytes_read =
      getline(&(input_buffer->buffer), &(input_buffer->buffer_length), stdin);

  if (bytes_read <= 0) {
    printf("Error reading input\n");
    exit(EXIT_FAILURE);
  }

  // ignore trailing newline
  input_buffer->input_length = bytes_read - 1;
  input_buffer->buffer[bytes_read - 1] = 0;
}
