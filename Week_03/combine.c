/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** dfs(int cnt, int max, int *cur, int curMax, int n, int *returnSize, int ** returnColumnSizes, int **returnArray) 
{
    if (cnt == max) {
        int i;
        returnArray[*returnSize] = (int*)malloc(sizeof(int) * (max + 1));
        for (i = 0; i < max; i++) {
            printf("%d ", cur[i]);
            returnArray[*returnSize][i] = cur[i];
        }
        (*returnColumnSizes)[*returnSize] = max;
        (*returnSize)++;
        *returnColumnSizes = (int*) realloc(*returnColumnSizes, sizeof(int) * (*returnSize +1)); 
        returnArray = (int**) realloc(returnArray, sizeof(int*) * (*returnSize +1)); 
        printf("\n");
        return returnArray;
    }
    int j ;
    for (j = curMax + 1; j <= n; j++)
    {
        cur[cnt] = j;
        returnArray = dfs(cnt+1, max, cur, j, n, returnSize, returnColumnSizes, returnArray);
    }
    return returnArray;
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes){
    int *current = (int*)malloc(sizeof(int) * (k + 1));
    int **returnArray = (int**)malloc(sizeof(int*));
    *returnColumnSizes = (int*)malloc(sizeof(int));
    memset(current, 0, sizeof(int) * (k + 1));
    *returnSize = 0;
    returnArray = dfs(0, k,current, 0, n, returnSize, returnColumnSizes, returnArray);
    return returnArray;
}