int max(int a, int b) {
    return a > b ? a : b;
}
int maximalSquare(char** matrix, int matrixSize, int* matrixColSize){
    if (matrixSize == 0) {
        return 0;
    }
    int** dp = (int**)malloc(sizeof(int*) * matrixSize);
    int i;
    int j;
    int ans = 0;
    int k;
    for (i = 0; i < matrixSize; i++) {
        dp[i] = (int*)malloc(sizeof(int) * matrixColSize[i]);
    }
    for (j = 0; j < matrixColSize[matrixSize - 1]; j++) {
        if (matrix[matrixSize - 1][j] == '0') {
            dp[matrixSize - 1][j] = 0;
        } else {
            dp[matrixSize - 1][j] = 1;
            ans = 1;
        }     
    }
    //printf("i = %d, j=%d, val=%d\n", i, matrixColSize[0] - 1, matrix[3][4]);
    for (i = 0; i < matrixSize; i++) {
        if (matrix[i][matrixColSize[0] - 1] == '0') {
            dp[i][matrixColSize[0] - 1] = 0;
            //printf("i = %d, j=%d, \n", i, matrixColSize[0] - 1);
        } else {
            dp[i][matrixColSize[0] - 1] = 1;
            ans = 1;
        }
    }

    for (i = matrixSize - 2; i >= 0; i--) {
        for (j = matrixColSize[i] - 2; j >= 0; j--) {
            for (k = 0; k * k <= dp[i + 1][j + 1]; k++) {
                //printf("%d,%d,%d,%d\n", i,j, k, dp[3][4]);
                if ((matrix[i + k][j] == '0') || (matrix[i][j + k] == '0')) {
                    break;
                }
            }
            //printf("i = %d, j = %d, k = %d\n",i,j, k);
            dp[i][j] = k * k;
            //printf("i = %d, j = %d, k = %d\n",i,j, k);
            ans = max(ans, k * k);
        }
    }
    return ans;
}
//定义状态
//递推方程.dp[i][j] 代表从 i行 j 列为左上角的最大