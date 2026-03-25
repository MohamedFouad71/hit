#include "hooks.h"
#include <stdio.h>

int applypatch_msg_hook() {
  FILE *fp = fopen(".hit/hooks/applypatch-msg.sample", "w");
  if (fp == NULL) {
    printf("Error: fopen .hit/hooks/applypatch-msg.sample\n");
    return -1;
  }
  fprintf(fp, "#!/bin/sh\n"
    "#\n"
    "# An example hook script to check the commit log message taken by\n"
    "# applypatch from an e-mail message.\n"
    "#\n"
    "# The hook should exit with non-zero status after issuing an\n"
    "# appropriate message if it wants to stop the commit.  The hook is\n"
    "# allowed to edit the commit message file.\n"
    "#\n"
    "# To enable this hook, rename this file to \"applypatch-msg\".\n"
    "\n"
    ". git-sh-setup\n"
    "commitmsg=\"$(git rev-parse --git-path hooks/commit-msg)\"\n"
    "test -x \"$commitmsg\" && exec \"$commitmsg\" ${1+\"$@\"}\n"
    ":\n"
    "");
  fclose(fp);
  return 0;
}
