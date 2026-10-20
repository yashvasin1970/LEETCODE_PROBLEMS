
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int** triangle = malloc(numRows * sizeof(int*));

    *returnSize = numRows;
    *returnColumnSizes = malloc(numRows * sizeof(int));

    for (int i = 0; i < numRows; i++) {
        triangle[i] = malloc((i + 1) * sizeof(int));
        (*returnColumnSizes)[i] = i + 1;

        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                triangle[i][j] = 1;
            } else {
                triangle[i][j] =
                    triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
        }
    }

    return triangle;
}
