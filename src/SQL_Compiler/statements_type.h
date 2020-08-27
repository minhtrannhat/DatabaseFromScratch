#pragma once

typedef enum {STATEMENT_INSERT, STATEMENT_SELECT} StatementType;

typedef struct {
  StatementType type;
} Statement;
