class Solution {
public:
    double (vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int low = 0;
        int high = m;
        int total_half = (m + n + 1) / 2;

        while (low <= high) {
            int i = low + (high - low) / 2;
            int j = total_half - i;

            int left_max1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int right_min1 = (i == m) ? INT_MAX : nums1[i];
            int left_max2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int right_min2 = (j == n) ? INT_MAX : nums2[j];

            if (left_max1 <= right_min2 && left_max2 <= right_min1) {
                if ((m + n) % 2 == 1) {
                    return max(left_max1, left_max2);
                } else {
                    return (max(left_max1, left_max2) + min(right_min1, right_min2)) / 2.0;
                }
            } else if (left_max1 > right_min2) {
                high = i - 1;
            } else {
                low = i + 1;
            }
        }
        return 0.0;
        
    }
};
