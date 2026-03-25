#include "init.h"
#include "aliases.h"
#include "create_repo_dirs.h"
#include "create_repo_files.h"
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

//------------------------ Static helper functions prototypes ------------------------

static void print_messsage();

//------------------------ Public function ------------------------

int init() {
  if (access(".hit", F_OK) == 0) {
    printf("%sRepo Already Exists!\n%s", RED, RESET);
    return -1;
  }

  if (create_repo_dirs() == -1)
    return -1;
  if (create_repo_files() == -1)
    return -1;

  print_messsage();
  return 0;
}

static void print_messsage() {
  // all the messages are in yellow color
  printf("%s hint: Using 'master' as the name for the initial branch. This "
         "default branch name\n%s", YELLOW, RESET);
  printf("%s hint: is subject to change. To configure the initial branch name to "
         "use in all\n%s", YELLOW, RESET);
  printf("%s hint: of your new repositories, which will suppress this warning, "
         "call:\n%s", YELLOW, RESET);
  printf("%s hint:\n%s", YELLOW, RESET);
  printf("%s hint:\n%s", YELLOW, RESET);
  printf("%s hint: Names commonly chosen instead of 'master' are 'main', 'trunk' "
         "and\n%s", YELLOW, RESET);
  printf("%s hint: 'development'. The just-created branch can be renamed via this "
         "command:\n%s", YELLOW, RESET);
  printf("%s hint:\n%s", YELLOW, RESET);
  printf("%s hint:  hit branch -m <name>\n%s", YELLOW, RESET);
  printf("%sInitialized empty hit repository in /.hit/%s\n%s", YELLOW, getcwd(NULL, 0), RESET);
}