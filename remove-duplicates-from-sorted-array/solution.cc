class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int firstPos = 0;
        int secondPos = 0;
        while (secondPos < nums.size()) {
            if (secondPos+1 >= nums.size() || nums[secondPos] != nums[secondPos+1]) {
                nums[firstPos] = nums[secondPos];
                firstPos++;
            }
            secondPos++;
        }
        return firstPos;
    }
};
