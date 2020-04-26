/*
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){ 
    int * arrayList = (int*)malloc(sizeof(int)*2);
    int i,j;
    memset(arrayList, 0,sizeof(int)*2);
    *returnSize = 0;
    for (i = 0; i<numsSize; i++)
    {
        for(j = i+1; j <numsSize; j++)
        {
            if ((nums[i] + nums[j]) == target)
            {
                *returnSize = 2; 
                arrayList[0] = i;
                arrayList[1] = j;
                return arrayList;
            }
        }
    }
    return arrayList;
}
