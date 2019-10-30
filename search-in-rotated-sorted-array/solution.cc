class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int smallIdx = 0;
        int bigIdx = nums.size();

        while(smallIdx < bigIdx - 1) {
            int middleIdx = (smallIdx + bigIdx) / 2;
            int middle = nums[middleIdx];
            if (target == middle) {
                return middleIdx;
            } else if (nums[smallIdx] <= middle) {
                if (nums[smallIdx] <= target && target <= middle) {
                    bigIdx = middleIdx;
                } else {
                    smallIdx = middleIdx;
                }
            } else {
                if (middle <= target && target <= nums[bigIdx - 1]) {
                    smallIdx = middleIdx;
                } else {
                    bigIdx = middleIdx;
                }
            }
        }
        if (smallIdx < nums.size() && nums[smallIdx] == target) {
            return smallIdx;
        } else if (smallIdx + 1 < nums.size() && nums[smallIdx + 1] == target) {
            return smallIdx + 1;
        }
        return -1;
    }
};
