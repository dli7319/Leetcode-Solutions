class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            auto result = hash.find(nums[i]);
            if (result != hash.end() && i - result->second <= k) {
                return true;
            }
            hash[nums[i]] = i;
        }
        return false;
    }
};
