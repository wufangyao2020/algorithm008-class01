int comp(const void* p, const void* q) {
    int a = (*(int*)p);
    int b = (*(int*)q);
    if (a > b) {
        return 1;
    } else if ( a < b) {
        return -1;
    } else {
        return 0;
    }
}
int mergeSort(int* nums, int left, int right) {
    if (left >= right) {
        //printf("left=%d, right=%d\n", left, right);
        return 0;
    }
    int mid = left + (right - left)/2;
    int i = left;
    int j = mid + 1;
    int count = mergeSort(nums, left, mid) + mergeSort(nums, mid + 1, right);

    for (i = left; i <= mid; i++) {
        while ((j <= right) && (nums[i] > 2 * (long) nums[j])) {
            //printf("i=%d, j=%d\n", i, j); // 此处用二分查找可以做少量的优化. 即 二分查找，找到右边界.
            j++;
        }  
        //printf("j = %d\n", j);
        count += j - mid - 1;
    }
    qsort(nums + left, right - left + 1, sizeof(int), comp);
    return count;
}
int reversePairs(int* nums, int numsSize){
    return mergeSort(nums, 0, numsSize - 1);
}
