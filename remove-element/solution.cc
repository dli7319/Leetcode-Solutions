class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int firstPos = 0;
        int secondPos = 0;
        while (secondPos < nums.size()) {
            if (nums[secondPos] != val) {
                nums[firstPos] = nums[secondPos];
                firstPos++;
            }
            secondPos++;
        }
        return firstPos;
    }
};
