class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int c = n + m;
        while (m > 0 || n > 0) {
            if (n <= 0 || m > 0 && nums1[m-1] > nums2[n-1]) {
                nums1[--c] = nums1[--m];
            } else {
                nums1[--c] = nums2[--n];
            }
        }
    }
};
