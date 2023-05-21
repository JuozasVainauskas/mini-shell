#include <stdio.h>
#include <stdlib.h>
#include "read_line.h"
#include "split_line.h"
#include "execute.h"

void loop() {
    int status;
    do {
        printf("mini-shell > ");
        char *line = read_line();
        char **args = split_line(line);
        status = execute(args);
        free(line);
        free(args);
    } while (status);
}
