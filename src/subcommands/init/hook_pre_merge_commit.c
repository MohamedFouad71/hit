#include "hooks.h"
#include <stdio.h>

int pre_merge_commit_hook() {
  FILE *fp = fopen(".hit/hooks/pre-merge-commit.sample", "w");
  if (fp == NULL) {
    printf("Error: fopen .hit/hooks/pre-merge-commit.sample\n");
    return -1;
  }
  fprintf(fp, "#!/bin/sh\n"
    "#\n"
    "# An example hook script to verify what is about to be committed.\n"
    "# Called by \"git merge\" with no arguments.  The hook should\n"
    "# exit with non-zero status after issuing an appropriate message to\n"
    "# stderr if it wants to stop the merge commit.\n"
    "#\n"
    "# To enable this hook, rename this file to \"pre-merge-commit\".\n"
    "\n"
    ". git-sh-setup\n"
    "test -x \"$GIT_DIR/hooks/pre-commit\" &&\n"
    "        exec \"$GIT_DIR/hooks/pre-commit\"\n"
    ":\n"
    "");
  fclose(fp);
  return 0;
}
