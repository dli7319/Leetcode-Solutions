class Solution {
public:
    template<class S, class T> using umap=std::unordered_map<S,T>;
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        umap<int, umap<int, umap<int, int>>> memo;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                int curr = nums[i] + nums[j];
                int m = j+1;
                int n = nums.size() - 1;
                while (m < n) {
                    int total = curr + nums[m] + nums[n];
                    if (total == target) {
                        memo[nums[i]][nums[j]][nums[m]] = nums[n];
                    }
                    if (total < target) {
                        m++;
                    } else {
                        n--;
                    }
                }
            }
        }

        vector<vector<int>> ans;
        for (auto a1 : memo) {
            for (auto a2 : a1.second) {
                for (auto a3 : a2.second) {
                    ans.push_back(vector<int>{a1.first, a2.first, a3.first, a3.second});
                }
            }
        }
        return ans;
    }
};
