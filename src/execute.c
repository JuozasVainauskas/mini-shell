#include "execute.h"
#include "built_in.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <unistd.h>

int execute(char **args) {
    if (args[0] == NULL) {
        return 1;
    }

    for(int i = 0; i < len_built_ins(); i++) {
        if (strcmp(args[0], built_ins[i]) == 0) {
            return (built_in_func[i])(args);
        }
    }

    return run(args);
}

int run(char **args) {
    int status;
    pid_t pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("mini-shell");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("mini-shell");
    } else {
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    return 1;
}
