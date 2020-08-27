#include "../REPL/inputbuffer.h"
#include "./meta_commands.h"
#include "./statements_type.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma once

// free the memory allocated for input_buffer
void close_input_buffer(InputBuffer *input_buffer) {
  free(input_buffer->buffer);
  free(input_buffer);
}

MetaCommandResult do_meta_command(InputBuffer *input_buffer) {
  if (strcmp(input_buffer->buffer, ".exit") == 0) {
    close_input_buffer(input_buffer);   
    exit(EXIT_SUCCESS);
  } else {
    return META_COMMAND_UNRECOGNIZED_COMMAND;
  }
}

void execute_statement(Statement *statement) {
  switch (statement->type) {
  case (STATEMENT_INSERT):
    printf("This is where we would do an insert.\n");
    break;
  case (STATEMENT_SELECT):
    printf("This is where we would do a select.\n");
    break;
  }
}

PrepareResult prepare_statement(InputBuffer *input_buffer,
                                Statement *statement) {
  if (strncmp(input_buffer->buffer, "insert", 6) == 0) {
    statement->type = STATEMENT_INSERT;
    return PREPARE_SUCCESS;
  }

  if (strcmp(input_buffer->buffer, "select") == 0) {
    statement->type = STATEMENT_SELECT;
    return PREPARE_SUCCESS;
  }

  return PREPARE_UNRECOGNIZED_STATEMENT;
}
