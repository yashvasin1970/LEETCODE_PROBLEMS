#include <stdlib.h>
#include <string.h>

char** fullJustify(char** words, int wordsSize, int maxWidth,
                   int* returnSize) {
    char **result = malloc(wordsSize * sizeof(char *));
    *returnSize = 0;

    int i = 0;

    while (i < wordsSize) {
        int j = i;
        int letters = 0;

        // Find the maximum number of words for this line
        while (j < wordsSize &&
               letters + strlen(words[j]) + (j - i) <= maxWidth) {
            letters += strlen(words[j]);
            j++;
        }

        int count = j - i;
        int spaces = maxWidth - letters;

        char *line = malloc((maxWidth + 1) * sizeof(char));
        int pos = 0;

        // Last line or line with one word: left-justify
        if (j == wordsSize || count == 1) {
            for (int k = i; k < j; k++) {
                int len = strlen(words[k]);
                memcpy(line + pos, words[k], len);
                pos += len;

                if (k < j - 1)
                    line[pos++] = ' ';
            }

            while (pos < maxWidth)
                line[pos++] = ' ';
        } else {
            int gaps = count - 1;
            int each = spaces / gaps;
            int extra = spaces % gaps;

            for (int k = i; k < j; k++) {
                int len = strlen(words[k]);
                memcpy(line + pos, words[k], len);
                pos += len;

                if (k < j - 1) {
                    int gapSpaces = each + (extra > 0 ? 1 : 0);

                    for (int s = 0; s < gapSpaces; s++)
                        line[pos++] = ' ';

                    if (extra > 0)
                        extra--;
                }
            }
        }

        line[maxWidth] = '\0';
        result[(*returnSize)++] = line;
        i = j;
    }

    return result;
}
