class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int slen = S.length();
        vector<int> dl(slen);
        if (slen == 0) {
            return dl;
        }
        dl[0] = S.at(0) == C ? 0 : 99999;
        for (int i = 1; i < slen; i++) {
            if (S.at(i) == C) {
                dl[i] = 0;
            } else {
                dl[i] = 1 + dl[i-1];
            }
        }
        for (int i = slen - 2; i >= 0; i--) {
            dl[i] = min(dl[i], 1 + dl[i+1]);
        }
        return dl;
    }
};
