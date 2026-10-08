#include <stdlib.h>
#include <string.h>

char* countAndSay(int n) {
    char* current = malloc(5000);
    strcpy(current, "1");

    for (int step = 1; step < n; step++) {
        char* next = malloc(5000);
        int pos = 0;

        for (int i = 0; current[i] != '\0'; ) {
            char digit = current[i];
            int count = 0;

            while (current[i] == digit) {
                count++;
                i++;
            }

            pos += sprintf(next + pos, "%d%c", count, digit);
        }

        next[pos] = '\0';

        free(current);
        current = next;
    }

    return current;
}