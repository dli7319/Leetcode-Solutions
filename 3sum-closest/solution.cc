class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int closest = target > 0 ? INT_MIN : INT_MAX;
        int del = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            int curr = nums[i];
            int j = i+1;
            int k = nums.size()-1;
            while (j < k) {
                int total = curr + nums[j] + nums[k];
                if (abs(target - total) < del) {
                    del = abs(target - total);
                    closest = total;
                    if (del == 0) {
                        return total;
                    }
                }
                if (total < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return closest;
    }
};
