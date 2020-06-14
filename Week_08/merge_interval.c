/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int comp(const void *p, const void *q) {
    int* arrayA =  (*(int**)p);
    int* arrayB =  (*(int**)q);
    if (arrayA[0] > arrayB[0]) {
        return 1;
    } else if (arrayA[0] < arrayB[0]) {
        return -1;
    } else {
        return 0;
    }
}
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    int i = 0;
    int j = i + 1;
    if (intervalsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    qsort(intervals, intervalsSize, sizeof(int*), comp);
    int rightVal = intervals[i][1];
    int leftVal  = intervals[i][0];
    int** returnArray = (int**)malloc(sizeof(int*) * intervalsSize);
    for (i = 0; i < intervalsSize; i++) {
        returnArray[i] = (int*)malloc(sizeof(int) * 2);
    }
    *returnColumnSizes = (int*)malloc(sizeof(int) * intervalsSize);
    memset(*returnColumnSizes, 0, sizeof(int) * intervalsSize);
    *returnSize = 0;
    while(j < intervalsSize) {
        if (rightVal >= intervals[j][0]) {
            if (rightVal < intervals[j][1]) {
                rightVal = intervals[j][1];
            }
            j++;
        } else {
            returnArray[*returnSize][0] = leftVal;
            returnArray[*returnSize][1] = rightVal;
            (*returnColumnSizes)[*returnSize] = 2;
            (*returnSize)++;
            leftVal = intervals[j][0];
            rightVal = intervals[j][1];
            j++;
        }
    }
    returnArray[*returnSize][0] = leftVal;
    returnArray[*returnSize][1] = rightVal;
    (*returnColumnSizes)[*returnSize] = 2;
    (*returnSize)++;
    return returnArray;
}

//排序. 如果发现 a[i][1] > a[j][0], 则合并. a[i][0]  a[j][1]. 合并了. a[i][1] < a[j][0]
//