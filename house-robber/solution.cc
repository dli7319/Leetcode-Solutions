class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        // Best if we do rob i
        vector<int> memo1(nums.size());
        // Best if we don't rob i
        vector<int> memo2(nums.size());

        memo1[0] = nums[0];
        memo2[0] = 0;
        for (int i = 1; i < nums.size(); i++) {
            memo1[i] = max(memo1[i-1], nums[i] + memo2[i-1]);
            memo2[i] = max(memo1[i-1], memo2[i-1]);
        }
        return max(memo1[nums.size()-1], memo2[nums.size()-1]);
    }
};
