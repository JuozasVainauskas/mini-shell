#include "built_in.h"
#include <stdio.h>

char *built_ins[] = {
        "cd",
        "help",
        "exit"
};

// Array of function pointers. Function receives an array of strings and returns an int
int (*built_in_func[]) (char **) = {
        &cd,
        &help,
        &exit_shell
};

int len_built_ins() {
    return sizeof(built_ins) / sizeof(char *);
}

int cd(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "mini-shell: expected argument to \"cd\"\n");
    } else {
        if (chdir(args[1]) != 0) {
            perror("mini-shell");
        }
    }
    return 1;
}

int help(char **args) {
    printf("Built in commands:\n");
    for (int i = 0; i < len_built_ins(); i++) {
        printf("  %s\n", built_ins[i]);
    }
    return 1;
}

int exit_shell(char **args) {
    return 0;
}
