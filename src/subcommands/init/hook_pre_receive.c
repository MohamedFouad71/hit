#include "hooks.h"
#include <stdio.h>

int pre_receive_hook() {
  FILE *fp = fopen(".hit/hooks/pre-receive.sample", "w");
  if (fp == NULL) {
    printf("Error: fopen .hit/hooks/pre-receive.sample\n");
    return -1;
  }
  fprintf(fp, "#!/bin/sh\n"
    "#\n"
    "# An example hook script to make use of push options.\n"
    "# The example simply echoes all push options that start with 'echoback='\n"
    "# and rejects all pushes when the \"reject\" push option is used.\n"
    "#\n"
    "# To enable this hook, rename this file to \"pre-receive\".\n"
    "\n"
    "if test -n \"$GIT_PUSH_OPTION_COUNT\"\n"
    "then\n"
    "	i=0\n"
    "	while test \"$i\" -lt \"$GIT_PUSH_OPTION_COUNT\"\n"
    "	do\n"
    "		eval \"value=\\$GIT_PUSH_OPTION_$i\"\n"
    "		case \"$value\" in\n"
    "		echoback=*)\n"
    "			echo \"echo from the pre-receive-hook: ${value#*=}\" >&2\n"
    "			;;\n"
    "		reject)\n"
    "			exit 1\n"
    "		esac\n"
    "		i=$((i + 1))\n"
    "	done\n"
    "fi\n"
    "");
  fclose(fp);
  return 0;
}
