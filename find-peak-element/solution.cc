class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size();
        while (l < r - 1) {
            int m = (l + r) / 2;
            if ( (m == 0 || nums[m-1] < nums[m]) &&(m==nums.size()-1 ||  nums[m] > nums[m+1])) {
                return m;
            } else if (nums[m-1] <= nums[m] && nums[m] <= nums[m+1]) {
                l = m;
            } else {
                r = m;
            }
        }
        return l;
    }
};
