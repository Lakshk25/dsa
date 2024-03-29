class Solution
{
public:
    int findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int m = nums1.size();
        int n = nums2.size();
        if (m > n)
            return findMedianSortedArrays(nums2, nums1, k);

        int total = m + n;
        // if k = 10 and m = 4 and n = 12 low = 10 - 4 = 6 means whitout this error coz arr1 not contains only 4 elems
        int low = max(0, k - m), high = min(k, n);
        while (low <= high)
        {
            int mid1 = low + (high - low) / 2;
            int mid2 = k - mid1;

            int l1 = INT_MIN;
            int l2 = INT_MIN;
            int r1 = INT_MAX;
            int r2 = INT_MAX;

            if (mid1 < m)
                r1 = nums1[mid1];
            if (mid2 < n)
                r2 = nums2[mid2];

            if (mid1 - 1 >= 0)
                l1 = nums1[mid1 - 1];
            if (mid2 - 1 >= 0)
                l2 = nums2[mid2 - 1];

            if (l1 <= r2 && l2 <= r1)
            {
                return max(l1, l2);
            }
            else if (l1 > r2)
                high = mid1 - 1;
            else
                low = mid1 + 1;
        }
        return 0;
    }
};