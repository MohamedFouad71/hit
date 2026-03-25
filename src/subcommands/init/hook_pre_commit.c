#include "hooks.h"
#include <stdio.h>

int pre_commit_hook() {
  FILE *fp = fopen(".hit/hooks/pre-commit.sample", "w");
  if (fp == NULL) {
    printf("Error: fopen .hit/hooks/pre-commit.sample\n");
    return -1;
  }
  fprintf(fp, "#!/bin/sh\n"
    "#\n"
    "# An example hook script to verify what is about to be committed.\n"
    "# Called by \"git commit\" with no arguments.  The hook should\n"
    "# exit with non-zero status after issuing an appropriate message if\n"
    "# it wants to stop the commit.\n"
    "#\n"
    "# To enable this hook, rename this file to \"pre-commit\".\n"
    "\n"
    "if git rev-parse --verify HEAD >/dev/null 2>&1\n"
    "then\n"
    "	against=HEAD\n"
    "else\n"
    "	# Initial commit: diff against an empty tree object\n"
    "	against=$(git hash-object -t tree /dev/null)\n"
    "fi\n"
    "\n"
    "# If you want to allow non-ASCII filenames set this variable to true.\n"
    "allownonascii=$(git config --type=bool hooks.allownonascii)\n"
    "\n"
    "# Redirect output to stderr.\n"
    "exec 1>&2\n"
    "\n"
    "# Cross platform projects tend to avoid non-ASCII filenames; prevent\n"
    "# them from being added to the repository. We exploit the fact that the\n"
    "# printable range starts at the space character and ends with tilde.\n"
    "if [ \"$allownonascii\" != \"true\" ] &&\n"
    "	# Note that the use of brackets around a tr range is ok here, (it's\n"
    "	# even required, for portability to Solaris 10's /usr/bin/tr), since\n"
    "	# the square bracket bytes happen to fall in the designated range.\n"
    "	test $(git diff --cached --name-only --diff-filter=A -z $against |\n"
    "	  LC_ALL=C tr -d '[ -~]\\0' | wc -c) != 0\n"
    "then\n"
    "	cat <<\\EOF\n"
    "Error: Attempt to add a non-ASCII file name.\n"
    "\n"
    "This can cause problems if you want to work with people on other platforms.\n"
    "\n"
    "To be portable it is advisable to rename the file.\n"
    "\n"
    "If you know what you are doing you can disable this check using:\n"
    "\n"
    "  git config hooks.allownonascii true\n"
    "EOF\n"
    "	exit 1\n"
    "fi\n"
    "\n"
    "# If there are whitespace errors, print the offending file names and fail.\n"
    "exec git diff-index --check --cached $against --\n"
    "");
  fclose(fp);
  return 0;
}
