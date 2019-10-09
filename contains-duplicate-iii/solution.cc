class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (t < nums.size() / 2) {
                for (int j = num-t; j <= num+t; j++) {
                    auto result = hash.find(j);
                    if (result != hash.end() && i - result->second <= k) {
                        return true;
                    }
                }
            } else {
                for (auto j = hash.begin(); j != hash.end(); j++ ) {
                    if (abs((long)num - (long)j->first) <= t && i - j->second <= k) {
                        return true;
                    }
                }
            }
            hash[nums[i]] = i;
        }
        return false;
    }
};
