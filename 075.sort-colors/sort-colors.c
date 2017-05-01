void sortColors(int* nums, int numsSize) {
    int count[3] = {0, 0, 0};
    for (int i = 0; i < numsSize; i++)
        count[nums[i]]++;
    int pos = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < count[i]; j++) {
            nums[pos] = i;
            pos++;
        }
}