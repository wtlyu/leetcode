int findMin(int* nums, int numsSize) {
    int maxn = nums[numsSize - 1];
    for (int i = numsSize - 1; i >= 0; i--) 
        if (nums[i] > maxn) return maxn;
        else maxn = nums[i];
    return maxn;
}