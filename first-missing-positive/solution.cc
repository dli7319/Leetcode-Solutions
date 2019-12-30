class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.empty()) return 1;
        for (int i = 0; i < nums.size(); i++) {
            int temp = nums[i];
            while (temp-1 >= 0 &&
                   temp-1 < nums.size() &&
                   nums[temp-1] != temp) {
                int t2 = nums[temp-1];
                nums[temp-1] = temp;
                temp = t2;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i+1) {
                return i+1;
            }
        }
        return nums.size()+1;
    }
};
