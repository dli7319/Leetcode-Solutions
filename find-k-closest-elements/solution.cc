class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int i = 0;
        int j = arr.size();
        while (i < j - 1) {
            int middleIdx = (i + j) /2;
            // cout << arr[i] << " " << i << " " << j  << " " << middleIdx<< endl;
            if (arr[middleIdx] > x) {
                j = middleIdx;
            } else {
                i = middleIdx;
            }
        }
        stack<int> l;
        queue<int> r;
        int ct = 0;
        while (ct < k) {
            if (i >= 0 && j < arr.size()) {
                int left = arr[i];
                int right = arr[j];
                if (x - left <= right - x) {
                    l.push(left);
                    i--;
                } else {
                    r.push(right);
                    j++;
                }
            } else if (i >= 0) {
                l.push(arr[i]);
                i--;
            } else {
                r.push(arr[j]);
                j++;
            }
            ct++;
        }
        vector<int> finalR(k);
        ct = 0;
        while (!l.empty()) {
            finalR[ct] = l.top();
            l.pop();
            ct++;
        }
        while (!r.empty()) {
            finalR[ct] = r.front();
            r.pop();
            ct++;
        }
        return finalR;
    }
};
