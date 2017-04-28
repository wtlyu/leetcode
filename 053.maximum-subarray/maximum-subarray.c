int maxSubArray(int* nums, int numsSize) {
    int presum = fmin(0, nums[0]), sum = nums[0], ans = nums[0];
    for (int i = 1; i < numsSize; i++) {
        sum += nums[i];
        if (sum - presum > ans)
            ans = sum - presum;
        if (sum < presum)
            presum = sum;
    }
    return ans;
}