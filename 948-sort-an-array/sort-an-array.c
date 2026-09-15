/**
 * Note: The returned array must be malloced, assume caller calls free().
 */ 
 void sortArrayHelper(int* nums, int left, int right) {
    if (left >= right)
        return;

    int i = left;
    int j = right;
    int pivot = nums[(left + right) / 2];

    while (i <= j) {
        while (nums[i] < pivot)
            i++;

        while (nums[j] > pivot)
            j--;

        if (i <= j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
        }
    }

    if (left < j)
        sortArrayHelper(nums, left, j);

    if (i < right)
        sortArrayHelper(nums, i, right);
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;

    if (numsSize > 1)
        sortArrayHelper(nums, 0, numsSize - 1);

    return nums;
}