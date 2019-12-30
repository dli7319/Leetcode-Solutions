class Solution {
public:

    // O(n^2) time
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        unordered_map<int, unordered_map<int, int>> memo1;
        vector<vector<int>> ans2;
        for (int i = 0; i < nums.size(); i++) {
            while (i+4 < nums.size() &&
                   nums[i] == nums[i+1] &&
                   nums[i] == nums[i+2] &&
                   nums[i] == nums[i+3]) {
                i++;
            }
            int curr = -nums[i];
            int j = i+1;
            int k = nums.size() - 1;
            while(j < k) {
                int total = nums[j] + nums[k];
                if (total == curr) {
                    memo1[nums[i]][nums[j]] = nums[k];
                }
                if (total <= curr) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        for (auto kv1 : memo1) {
            for (auto kv2 : kv1.second) {
                ans2.push_back(vector<int>{kv1.first, kv2.first, kv2.second});
            }
        }
        return ans2;
    }
};
