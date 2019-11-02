class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size();
        while (low < high - 1) {
            int middle = (low + high) / 2;
            int middleVal = nums[middle];
            if (middleVal == target) {
                return middle;
            } else if ( middleVal < target) {
                low = middle;
            } else {
                high = middle;
            }
        }
        if (target <= nums[low]) {
            return low;
        } else {
            return low+1;
        }
    }
};
