double findMedianSortedArrays(int* nums1, int nums1Size,
                              int* nums2, int nums2Size) {
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size,
                                      nums1, nums1Size);
    }

    int m = nums1Size;
    int n = nums2Size;

    int low = 0, high = m;

    while (low <= high) {
        int cut1 = (low + high) / 2;
        int cut2 = (m + n + 1) / 2 - cut1;

        int left1 = (cut1 == 0) ? -2147483648 : nums1[cut1 - 1];
        int right1 = (cut1 == m) ? 2147483647 : nums1[cut1];

        int left2 = (cut2 == 0) ? -2147483648 : nums2[cut2 - 1];
        int right2 = (cut2 == n) ? 2147483647 : nums2[cut2];

        if (left1 <= right2 && left2 <= right1) {

            if ((m + n) % 2 == 0) {
                int leftMax = (left1 > left2) ? left1 : left2;
                int rightMin = (right1 < right2) ? right1 : right2;

                return (leftMax + rightMin) / 2.0;
            } 
            else {
                return (left1 > left2) ? left1 : left2;
            }
        }

        else if (left1 > right2) {
            high = cut1 - 1;
        }

        else {
            low = cut1 + 1;
        }
    }

    return 0.0;
}