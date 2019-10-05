class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        vector<int> best_a_j(A.size());
        best_a_j[A.size()-1] = A[A.size()-1] - (A.size() - 1);
        for (int i = A.size() - 2; i >= 0; i--) {
            best_a_j[i] = max(A[i] - i, best_a_j[i+1]);
        }
        int best_a_i = A[0];
        int best = best_a_i + best_a_j[1];
        for (int i = 1; i < A.size() - 1; i++) {
            best_a_i = max(A[i] + i, best_a_i);
            best = max(best, best_a_i + best_a_j[i+1]);
        }
        return best;
    }
};
