/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 int comp(const void *p1, const void *p2)
 {
     char a = *((char*)p1);
     char b = *((char*)p2);
     return (a - b);
 }
char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    int i = 0;
    int j;
    char** strsTmp = (char**)malloc(sizeof(char*)* strsSize);
    for (i = 0; i < strsSize; i++) {
        int tmplen = strlen(strs[i]) + 1;
        strsTmp[i] = malloc(tmplen);
        memset(strsTmp[i], 0, tmplen);
        strcpy(strsTmp[i],strs[i]);
        qsort(strsTmp[i], tmplen-1, sizeof(char), comp);
    }
    int totalSize = 0;
    int k;
    int localLen;
    int* visit = (int*)malloc(strsSize*sizeof(int));
    memset(visit, 0,sizeof(int)*strsSize);
    char *** returnArray = (char ***) malloc(sizeof(char**) * strsSize);
    for (i = 0; i < strsSize; i++) {
        returnArray[i] = (char**)malloc(sizeof(char*)*strsSize);
    }
    *returnColumnSizes = (int*)malloc(sizeof(int)*strsSize);
    for (i = 0; i < strsSize; i++) {
        if (visit[i] == 1) {
            continue;
        }
        k = 0;
        localLen = strlen(strs[i]);
        returnArray[totalSize][k] = (char*)malloc(localLen+1);
        memset(returnArray[totalSize][k],0,localLen+1);
        strcpy(returnArray[totalSize][k],strs[i]);
        k++;
        for (j = i+1; j < strsSize; j++) {
            if ((visit[j] == 0)&&(strcmp(strsTmp[i],strsTmp[j]) == 0)){
                visit[j] = 1;
                returnArray[totalSize][k] = (char*)malloc(localLen+1);
                memset(returnArray[totalSize][k],0,localLen+1);
                strcpy(returnArray[totalSize][k],strs[j]);
                k++;
            }
        }
        (*returnColumnSizes)[totalSize] = k;
        visit[i] = 1;
        totalSize++;
    }
    *returnSize = totalSize;
    return returnArray;
}