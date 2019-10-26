class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.empty()) return false;
        if (nums.size() == 1) return false;
        if (k < 0) k *= -1;
        unordered_set<int> hash;
        hash.insert(0);
        int64_t cdf = nums[0];
        int prev = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            cdf = nums[i] + cdf;
            if (k != 0 && hash.find(cdf % k) != hash.end()) {
                return true;
            } else if (k == 0 && hash.find(cdf) != hash.end()) {
                return true;
            }
            if (k != 0) {
                hash.insert(prev % k);
            } else {
                hash.insert(prev);
            }
            prev = cdf;
        }
        return false;
    }
};
