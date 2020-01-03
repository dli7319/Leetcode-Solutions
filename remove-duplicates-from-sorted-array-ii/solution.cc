class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int my_position = 0;
        int next_position = 0;
        while (next_position < nums.size()) {
            int val = nums[my_position] = nums[next_position];
            if (next_position+1 < nums.size() &&
                nums[next_position] == nums[next_position+1]) {
                my_position++;
                next_position++;
                nums[my_position] = val;
            }
            my_position++;
            next_position++;
            while (next_position < nums.size() && nums[next_position] == val) {
                next_position++;
            }
        }
        return my_position;
    }
};
