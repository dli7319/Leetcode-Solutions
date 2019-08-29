class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int i = 0;
        int j = arr.size();
        while (i < j - 1) {
            int middleIdx = (i + j) /2;
            if (arr[middleIdx] > x) {
                j = middleIdx;
            } else {
                i = middleIdx;
            }
        }
        int ct = 0;
        while (ct < k) {
            if (i >= 0 && j < arr.size()) {
                int left = arr[i];
                int right = arr[j];
                if (x - left <= right - x) {
                    i--;
                } else {
                    j++;
                }
            } else if (i >= 0) {
                i--;
            } else {
                j++;
            }
            ct++;
        }
        vector<int> finalR(k);
        ct = 0;
        while (ct < k) {
            i++;
            finalR[ct] = arr[i];
            ct++;
        }
        return finalR;
    }
};
