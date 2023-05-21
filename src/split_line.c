#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **split_line(char *line) {
    const char *token_delimiter = " \t\r\n\a";
    const int initial_buffer_size = 64;

    int buffer_size = initial_buffer_size;
    char **tokens = malloc(buffer_size * sizeof(char*));
    if (!tokens) {
        fprintf(stderr, "mini-shell: failed to allocate memory for tokens\n");
        exit(EXIT_FAILURE);
    }

    int position = 0;
    char *token = strtok(line, token_delimiter);
    while (token != NULL) {
        tokens[position] = token;
        position++;

        if (position >= buffer_size) {
            buffer_size += initial_buffer_size;
            tokens = realloc(tokens, buffer_size * sizeof(char*));
            if (!tokens) {
                fprintf(stderr, "mini-shell: failed to reallocate buffer memory\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, token_delimiter);
    }
    tokens[position] = NULL;
    return tokens;
}
