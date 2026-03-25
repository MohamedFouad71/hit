#pragma once
#define YELLOW "\033[1;33m"
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"

typedef char* string;

typedef struct {
  const char *name;
  int         has_arg;
  int        *flag;
  int         val;
} CliOption;