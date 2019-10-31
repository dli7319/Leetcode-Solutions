class Solution {
public:
    bool canJump(vector<int>& nums) {
        int start = 0;
        int end = 1;
        while (start < nums.size() && start < end) {
            int newEnd = end;
            for (int i = start; i < end && i < nums.size(); i++) {
                newEnd = max(newEnd, i + nums[i] + 1);
            }
            start = end;
            end = newEnd;
        }

        return end >= nums.size();
    }
};
