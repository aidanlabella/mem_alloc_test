#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GB_BYTES (1024 * 1024 * 1024)

int main(int c, char** argv) {
    if (c != 3) {
        fprintf(stderr, "Usage: ./mtest lim increment\n");
        return 1;
    }

    int max_gb = atoi(argv[1]);
    int inc = atoi(argv[2]);

    printf("Max gbs to alloc: %d GB\n", max_gb);
    printf("Incrementing in %dGB intervals!\n", inc);
    
    char** buf = malloc(max_gb * sizeof(char*));

    for (int i = 0; i < max_gb; i++) {
        printf("%d GB currently alloc'd, alloc %d more gb(s)?\n[y to continue]\n", i, inc);

        char resp[256];
        fgets(resp, sizeof(resp), stdin);
        resp[1] = '\0';

        if (strcasecmp(resp, "y") == 0) {
            int sect = i + inc;

            for (; i < sect; i++) {
                buf[i] = malloc(GB_BYTES);
                char* subbuf = buf[i];

                for (int j = 0; j < GB_BYTES; j++) {
                    subbuf[j] = 'X';
                }
            }
            --i;

            printf("Alloc'd %d more gb(s)\n", inc);
        } else {
            puts("OK! Exiting!");
            free(buf);

            return 0;
        }

    }

    puts("Limit reached! Goodbye!");

    free(buf);
    return 0;
}
