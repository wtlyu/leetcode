int missingNumber(int* nums, int numsSize) {
    long long ans = 0;
    for (int i = 0; i < numsSize; i++) 
        ans += nums[i];
    return ((numsSize * (numsSize+1)) >> 1) - ans;
}