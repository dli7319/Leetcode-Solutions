class Solution {
public:
    string vec2str(vector<int>& c) {
        ostringstream ans;
        for (auto a : c) {
            ans << a << ",";
        }
        return ans.str();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        unordered_set<string> memo2;
        vector<vector<vector<int>>> memo(target+1);
        for (int nt=1; nt <= target; nt++) {
            for (int i=0; i < candidates.size(); i++) {
                int delta = nt - candidates[i];
                if (delta == 0) {
                    memo[nt].push_back(vector<int>{candidates[i]});
                } else if (delta > 0) {
                    vector<vector<int>>& c = memo[delta];
                    for (vector<int> ct : c) {
                        ct.push_back(candidates[i]);
                        std::sort(ct.begin(), ct.end());
                        string key = vec2str(ct);
                        if (memo2.find(key) == memo2.end()) {
                            memo2.insert(key);
                            memo[nt].push_back(ct);
                        }
                    }
                }
            }
        }
        return memo[target];
    }
};
