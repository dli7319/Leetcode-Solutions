class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        // sort using a custom function object
        vector<int> indices(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            indices[i] = i;
        }
        sort(indices.begin(), indices.end(),  [&](int a, int b) {
            return nums[a] > nums[b];
        });
        vector<string> output(nums.size());
        if (nums.size() > 0)
            output[indices[0]] = "Gold Medal";
        if (nums.size() > 1)
            output[indices[1]] = "Silver Medal";
        if (nums.size() > 2)
            output[indices[2]] = "Bronze Medal";
        for (int i = 3; i < indices.size(); i++) {
            output[indices[i]] = to_string(1 + i);
        }
        return output;
    }
};
