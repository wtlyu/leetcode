/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int compare_ints(const void* a, const void* b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
 
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
 
    // return (arg1 > arg2) - (arg1 < arg2); // possible shortcut
    // return arg1 - arg2; // erroneous shortcut (fails if INT_MIN is present)
}

int* twoSum(int* nums, int numsSize, int target) {
    int nums_back [numsSize];
    memcpy( nums_back, nums, numsSize*sizeof(int) );

    qsort(nums, numsSize, sizeof(int), compare_ints);
    int i = 0, j = numsSize - 1;
    while (nums[i] + nums[j] != target) {
        if (nums[i] + nums[j] > target)
            j--;
        else
            i++;
    }
    int *ans = malloc(sizeof(int)*2);
    
    int k;
    for (k = 0; k < numsSize; k++) {
        if (nums_back[k] == nums[i]) {
            ans[0] = k;
            break;
        } else if (nums_back[k] == nums[j]) {
            ans[1] = k;
            break;
        } 
    }
    for (k = numsSize - 1; k >=0; k--) {
        if (nums_back[k] == nums[j]) {
            ans[1] = k;
            break;
        } else if (nums_back[k] == nums[i]) {
            ans[0] = k;
            break;
        } 
    }
    return ans;
}