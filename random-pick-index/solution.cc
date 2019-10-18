class Solution {
public:
    unordered_map<int, vector<int>> m;
    mt19937 gen;
    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            m[nums[i]].push_back(i);
        }
    }

    int pick(int target) {
        vector<int> possibilities = m[target];
        int a = -1;
        uniform_int_distribution<> dis(0, possibilities.size() - 1);
        return possibilities[dis(gen)];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
