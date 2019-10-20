class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        auto smaller = nums1.size() < nums2.size() ? nums1 : nums2;
        auto bigger = smaller == nums1 ? nums2 : nums1;
        unordered_map<int, int> elements;
        for (auto i : nums1) {
            elements[i]++;
        }
        unordered_map<int, int> intersection;
        for (auto i : nums2) {
            if (elements[i] > 0) {
                intersection[i] = min(intersection[i]+1, elements[i]);
            }
        }
        vector<int> iv;
        for (auto i : intersection) {
            for (int j=0; j < i.second; j++) {
                iv.push_back(i.first);
            }
        }
        return iv;
    }
};
