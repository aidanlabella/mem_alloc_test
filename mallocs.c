#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GB_BYTES (1024 * 1024 * 1024)

int main(int c, char** argv) {
    if (c != 2) {
        fprintf(stderr, "At least one arg required to specify max gb allocs!\n");
        return 1;
    }

    int max_gb = atoi(argv[1]);

    printf("Max gbs to alloc: %d GB\n", max_gb);
    
    char** buf = malloc(max_gb * sizeof(char*));

    for (int i = 0; i < max_gb; i++) {
        printf("%d GB currently alloc'd, alloc 1 more gb?\n", i);

        char resp[256];
        fgets(resp, sizeof(resp), stdin);
        resp[1] = '\0';

        if (strcasecmp(resp, "y") == 0) {
            buf[i] = malloc(GB_BYTES);

            char* subbuf = buf[i];

            for (int j = 0; j < GB_BYTES; j++) {
                subbuf[j] = 'X';
            }

            puts("Alloc'd 1 more gb");
        } else {
            puts("OK! Exiting!");
            free(buf);

            return 0;
        }

    }

    free(buf);
    return 0;
}
