class Solution {
public:
    void sortColors(vector<int>& nums) {
        int last_0 = -1;
        int last_1 = -1;
        int last_2 = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                last_0++;
                nums[last_0] = 0;
                if (last_1 >= 0) {
                    last_1 = max(last_1+1, last_0+1);
                    nums[last_1] = 1;
                }
                if (last_2 >= 0) {
                    last_2 = max(last_2+1, max(last_1+1, last_0+1));
                    nums[last_2] = 2;
                }
            } else if (nums[i] == 1) {
                last_1 = max(last_1+1, last_0+1);
                nums[last_1] = 1;
                if (last_2 >= 0) {
                    last_2 = max(last_2+1, max(last_1+1, last_0+1));
                    nums[last_2] = 2;
                }
            } else {
                last_2 = max(last_2+1, max(last_1+1, last_0+1));
                nums[last_2] = 2;
            }
        }
    }
};
