int removeDuplicates(int* nums, int numsSize) {
    int prepo = 0;
    for (int i = 1; i < numsSize; i++)
        if (nums[i] != nums[prepo]) {
            prepo++;
            nums[prepo] = nums[i];
        }
    return fmin(numsSize, prepo + 1);
}