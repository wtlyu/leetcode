/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int *ans = malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < numsSize; i++)
        ans[i] = 1;
    int left = 1, right = 1;
    for (int i = 0; i < numsSize; i++) {
        ans[i] *= left;
        ans[numsSize - i - 1] *= right;
        left *= nums[i];
        right *= nums[numsSize - i - 1];
    }
    return ans;
}