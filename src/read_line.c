#include "stdio.h"
#include "stdlib.h"
#include "read_line.h"

char *read_line() {
    const int initial_buffer_size = 1024;

    int buffer_size = initial_buffer_size;
    char *buffer = malloc(sizeof(char) * buffer_size);
    if(!buffer) {
        fprintf(stderr, "mini-shell: failed to allocate buffer memory\n");
        exit(EXIT_FAILURE);
    }

    int position = 0;
    while(1) {
        char c = getchar();
        if(c == EOF || c == '\n') {
            buffer[position] = '\0';
            return buffer;
        } else {
            buffer[position] = c;
        }
        position++;

        if(position >= buffer_size) {
            buffer_size += initial_buffer_size;
            buffer = realloc(buffer, sizeof(char) * buffer_size);
            if(!buffer) {
                fprintf(stderr, "mini-shell: failed to reallocate buffer memory\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}
