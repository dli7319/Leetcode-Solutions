class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        int letterCount = 0;
        const char *sc = S.c_str();
        int len = S.length();
        char letter[26];
        for (int i = 0; i < len; i++) {
            int c = sc[i] - 'a';
            int d = sc[i] - 'A';
            if (c >= 0 && c < 26) {
                letterCount++;
                letter[i] = c;
            } else if (d >= 0 && d < 26) {
                letterCount++;
                letter[i] = d;
            } else {
                letter[i] = -1;
            }
        }
        int resSize = pow(2, letterCount);
        vector<string> res(resSize);
        for (int i = 0; i < resSize; i++) {
            res[i] = S;
            int c = 0;
            for (int j = 0 ; j < len; j++) {
                int l = letter[j];
                if (letter[j] >= 0) {
                    int d = (int)pow(2, letterCount - c);
                    char newC = (i % d < d / 2) ? l + 'a' : l + 'A';
                    if (sc[j] != newC)
                        res[i].replace(j, 1, 1, newC);
                    c++;
                }
            }
        }
        return res;
    }
};
