#include "create_repo_files.h"
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "hooks.h"

//------------------------ Public function ------------------------

int create_repo_files() {
  if (create_head() == -1) return -1;
  if (create_config() == -1) return -1;
  if (create_description() == -1) return -1;
  if (create_info_exclude() == -1) return -1;
  if (create_hooks() == -1) return -1;

  return 0;
}

//------------------------ Helper functions definitions ------------------------

int create_head() {
  FILE *fp = fopen(".hit/HEAD", "w");
  if (fp == NULL) {
    printf("Error: fopen .hit/HEAD\n");
    printf("Unable to initialize the repo!\n");
    return -1;
  }
  fprintf(fp, "ref: refs/heads/master\n");
  fclose(fp);

  return 0;
}

int create_config() {
  FILE *fp = fopen(".hit/config", "w");
  if (fp == NULL) {
    printf("Error: fopen .hit/config\n");
    printf("Unable to initialize the repo!\n");
    return -1;
  }

  fprintf(fp, "[core]\n");
  fprintf(fp, "\trepositoryformatversion = 0\n");
  fprintf(fp, "\tfilemode = true\n");
  fprintf(fp, "\tbare = false\n");
  fprintf(fp, "\tlogallrefupdates = true\n");
  fprintf(fp, "\tignorecase = true\n");
  fclose(fp);

  return 0;
}

int create_description() {
  FILE *fp = fopen(".hit/description", "w");
  if (fp == NULL) {
    printf("Error: fopen .hit/config\n");
    printf("Unable to initialize the repo!\n");
    return -1;
  }
  fprintf(fp, "Unnamed repository; edit this file 'description' to name the "
              "repository.\n");
  fclose(fp);

  return 0;
}

int create_info_exclude() {
  FILE *fp = fopen(".hit/info/exclude", "w");
  if (fp == NULL) {
    printf("Error: fopen .hit/config\n");
    printf("Unable to initialize the repo!\n");
    return -1;
  }

  fprintf(fp, "# git ls-files --others --exclude-from=.git/info/exclude\n");
  fprintf(fp, "# Lines that start with '#' are comments.\n");
  fprintf(
      fp,
      "# For a project mostly in C, the following would be a good set of\n");
  fprintf(fp, "# exclude patterns (uncomment them if you want to use them):\n");
  fprintf(fp, "# *.[oa]\n");
  fprintf(fp, "# *~\n");
  fclose(fp);

  return 0;
}

int create_hooks() {
  if (applypatch_msg_hook() == -1)
    return -1;
  if (commit_msg_hook() == -1)
    return -1;
  if (fsmonitor_watchman_hook() == -1)
    return -1;
  if (pre_applypatch_hook() == -1)
    return -1;
  if (pre_commit_hook() == -1)
    return -1;
  if (pre_push_hook() == -1)
    return -1;
  if (pre_receive_hook() == -1)
    return -1;
  if (pre_rebase_hook() == -1)
    return -1;
  if (post_update_hook() == -1)
    return -1;
  if (pre_merge_commit_hook() == -1)
    return -1;
  if (push_to_checkout_hook() == -1)
    return -1;
  if (fsmonitor_watchman_hook() == -1)
    return -1;
  if (sendemail_validate_hook() == -1)
    return -1;
  if (update_hook() == -1)
    return -1;
  if (prepare_commit_msg_hook() == -1)
    return -1;
  return 0;
}