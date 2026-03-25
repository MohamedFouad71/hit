#pragma once

typedef char* string;

typedef struct {
  const char *name;
  int         has_arg;
  int        *flag;
  int         val;
} CliOption;