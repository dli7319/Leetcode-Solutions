class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        int size = A.size();
        int earliestPos = size;
        int smallestNumberSeen = INT_MAX;
        vector<int> largest(A);
        for (int i = size - 1; i >= 0; i--) {
            if (A[i] > smallestNumberSeen) {
                earliestPos = i;
                break;
            }
            smallestNumberSeen = min(A[i], smallestNumberSeen);
        }
        if (earliestPos == size) {
            return A;
        }
        int val1 = A[earliestPos];
        int largestNum = INT_MIN;
        int idx2 = -1;
        for (int i = earliestPos + 1; i <size; i++) {
            if (A[i] > largestNum && A[i] < val1) {
                idx2 = i;
                largestNum = A[i];
            }
        }
        largest[earliestPos] = largest[idx2];
        largest[idx2] = val1;
        return largest;
    }
};
