#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include "aliases.h"
#include "execute_subcommand.h"


int main(int argc, string *argv) {

    if (argc < 2) {
        printf("usage: hit <command> [<args>]\n");
        exit(1);
    }

    execute_subcommand(argv);
    

    return 0;
}