class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        vector<char> memo(bits.size());
        if (bits.empty()) return true;
        if (bits.size() == 1) return true;
        if (bits.size() == 2) return bits[0] == 0;
        memo[0] = bits[0] == 0;
        memo[1] = (memo[0] && bits[1] == 0) ||
            (bits[0] == 1 && bits[1] == 0) ||
            (bits[0] == 1 && bits[1] == 1);
        for (int i = 2; i < bits.size()-1; i++) {
            memo[i] = (memo[i-1] && bits[i] == 0) ||
                (memo[i-2] && bits[i-1] == 1 && bits[i] == 0) ||
                (memo[i-2] && bits[i-1] == 1 && bits[i] == 1);
        }
        return bits[bits.size()-2] == 0 || !memo[bits.size()-3];
    }
};
