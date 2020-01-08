class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int d1 = 0;
        int d2 = 0;
//         The idea is you count the number of times each bit appears mod 3
        for (int i = 0; i < nums.size(); i++) {
            int new_d2 = (d2 & ~nums[i]) | (nums[i] & d1);
            d1 = (nums[i] ^ d1) & (~d2);
            d2 = new_d2;
        }
        return d1;
    }
};
