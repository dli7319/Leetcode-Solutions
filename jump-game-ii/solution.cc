class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.empty()) return 0;
        int jumps = 0;
        int start = 0;
        int end = 1;
        int nextEnd = 0;
        while (end < nums.size()) {
            for (int i = start; i < end; i++) {
                nextEnd = max(nextEnd, i + nums[i]);
            }
            start = end;
            end = nextEnd + 1;
            nextEnd = 0;
            ++jumps;
            // std::cout << "start " << start << "End " << end << std::endl;
        }
        return jumps;
    }
};
