#include <string.h>
#include <stdio.h>

#include "options.h"
#include "execute_subcommand.h"
#include "init.h"

int execute_subcommand(string *argv) {
    string subcommand = argv[1];
    
    if (strcmp(subcommand, "init") == 0) {
        return init();
    }
    // red color
    printf("%sUnknown command: %s\n%s", RED, subcommand, RESET);
    return 1;
}