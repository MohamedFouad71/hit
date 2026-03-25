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
    printf("Repo Already Exists!\n");
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
  printf("hint: Using 'master' as the name for the initial branch. This "
         "default branch name\n");
  printf("hint: is subject to change. To configure the initial branch name to "
         "use in all\n");
  printf("hint: of your new repositories, which will suppress this warning, "
         "call:\n");
  printf("hint:\n");
  printf("hint:\n");
  printf("hint: Names commonly chosen instead of 'master' are 'main', 'trunk' "
         "and\n");
  printf("hint: 'development'. The just-created branch can be renamed via this "
         "command:\n");
  printf("hint:\n");
  printf("hint:   hit branch -m <name>\n");
  printf("Initialized empty hit repository in %s/.hit/\n", getcwd(NULL, 0));
}