#include "hooks.h"
#include <stdio.h>

int pre_applypatch_hook() {
  FILE *fp = fopen(".hit/hooks/pre-applypatch.sample", "w");
  if (fp == NULL) {
    printf("Error: fopen .hit/hooks/pre-applypatch.sample\n");
    return -1;
  }
  fprintf(fp, "#!/bin/sh\n"
    "#\n"
    "# An example hook script to verify what is about to be committed\n"
    "# by applypatch from an e-mail message.\n"
    "#\n"
    "# The hook should exit with non-zero status after issuing an\n"
    "# appropriate message if it wants to stop the commit.\n"
    "#\n"
    "# To enable this hook, rename this file to \"pre-applypatch\".\n"
    "\n"
    ". git-sh-setup\n"
    "precommit=\"$(git rev-parse --git-path hooks/pre-commit)\"\n"
    "test -x \"$precommit\" && exec \"$precommit\" ${1+\"$@\"}\n"
    ":\n"
    "");
  fclose(fp);
  return 0;
}
