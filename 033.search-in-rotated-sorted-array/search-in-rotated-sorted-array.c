int search(int* nums, int numsSize, int target) {
    int start = 0;
    for (int i = 0; i < numsSize; i++)
        if (nums[i] < nums[start]) {
            start = i;
            break;
        } 
    
    int l = 0, r = numsSize - 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (nums[(mid + start) % numsSize] == target) return (mid + start) % numsSize;
        if (nums[(mid + start) % numsSize] < target)
            l = mid + 1;
        else 
            r = mid - 1;
    }
    return -1;
}