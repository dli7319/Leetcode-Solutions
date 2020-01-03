class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) return;
        int largest_idx = nums.size() - 1;
        int largest = nums[largest_idx];
        for (int i = nums.size()-2; i >= 0; i--) {
            if (nums[i] < largest) {
                int smallest = largest;
                int smallest_idx = largest_idx;
                for (int j = nums.size()-1; j > i; j--) {
                    if (nums[j] > nums[i] && nums[j] <= smallest) {
                        smallest = nums[j];
                        smallest_idx = j;
                    }
                }
                nums[smallest_idx] = nums[i];
                nums[i] = smallest;
                std::sort(nums.begin()+i+1, nums.end());
                return;
            } else if (nums[i] > largest) {
                largest_idx = i;
                largest = nums[i];
            }
        }
        std::sort(nums.begin(), nums.end());
    }
};
