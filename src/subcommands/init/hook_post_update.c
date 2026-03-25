#include "hooks.h"
#include <stdio.h>

int post_update_hook() {
  FILE *fp = fopen(".hit/hooks/post-update.sample", "w");
  if (fp == NULL) {
    printf("Error: fopen .hit/hooks/post-update.sample\n");
    return -1;
  }
  fprintf(fp, "#!/bin/sh\n"
    "#\n"
    "# An example hook script to prepare a packed repository for use over\n"
    "# dumb transports.\n"
    "#\n"
    "# To enable this hook, rename this file to \"post-update\".\n"
    "\n"
    "exec git update-server-info\n"
    "");
  fclose(fp);
  return 0;
}
