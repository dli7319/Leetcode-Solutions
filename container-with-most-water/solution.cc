class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_water = 0;
        int start_idx = 0;
        int end_idx = height.size() - 1;
        while (start_idx < end_idx) {
            int distance = end_idx - start_idx;
            max_water = max(max_water, distance * min(height[start_idx], height[end_idx]));
            if (height[start_idx] > height[end_idx]) {
                end_idx--;
            } else {
                start_idx++;
            }
        }
        return max_water;
    }
};
