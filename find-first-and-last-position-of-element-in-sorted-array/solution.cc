class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return vector<int>{-1, -1};
        int l = 0;
        int r = nums.size();
        vector<int> ans(2);
        while (l + 1 < r) {
            int m = (l+r)/2;
            if (nums[m] < target) {
                l = m;
            } else {
                r = m;
            }
        }
        if (nums[l] == target) {
            ans[0] = l;
        } else if (l+1 < nums.size() && nums[l+1] == target) {
            ans[0] = l+1;
        } else {
            return vector<int>{-1, -1};
        }
        r = nums.size();
        while (l + 1< r) {
            int m = (l+r)/2;
            if (nums[m] <= target) {
                l = m;
            } else {
                r = m;
            }
        }
        ans[1] = l;
        return ans;
    }
};
