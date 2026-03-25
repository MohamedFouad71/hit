#include <string.h>

#include "options.h"
#include "execute_subcommand.h"
#include "init.h"

int execute_subcommand(string *argv) {
    string subcommand = argv[1];
    
    if (strcmp(subcommand, "init") == 0) {
        init();
        return 0;
    }
    
    return 1;
}