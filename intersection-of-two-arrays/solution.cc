class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        auto smaller = nums1.size() < nums2.size() ? nums1 : nums2;
        auto bigger = nums1.size() < nums2.size() ? nums2 : nums1;
        unordered_set<int> elements;
        for (auto i : smaller) {
            elements.insert(i);
        }
        unordered_set<int> intersect;
        for (auto i : bigger) {
            if (elements.find(i) != elements.end()) {
                intersect.insert(i);
            }
        }
        return vector<int>(intersect.begin(), intersect.end());
    }
};
