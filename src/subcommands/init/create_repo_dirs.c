#include "create_repo_dirs.h"
#include "aliases.h"
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

const int NUM_DIRS = 10;
string dirs[] =
{
    ".hit",
    ".hit/branches",
    ".hit/info",
    ".hit/hooks",
    ".hit/objects",
    ".hit/objects/info",
    ".hit/objects/pack",
    ".hit/refs",
    ".hit/refs/heads",
    ".hit/refs/tags"
};

int create_repo_dirs() {
    for (int i = 0; i < NUM_DIRS; i++) {
        if(mkdir(dirs[i], 0755) == -1) {
            printf("Error: mkdir %s\n", dirs[i]);
            printf("Unable to initialize the repo!\n");
            return -1;
        }
    }
    return 0;
}
