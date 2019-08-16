class Solution {
public:
    int findSubstringInWraproundString(string p) {
        if (p.length() == 0) {
            return 0;
        }
        int key[26];
        int maxKey[26];
        for (int i = 0; i < 26; i++) {
            key[i] = 0;
            maxKey[i] = 0;
        }
        const char *pPtr = p.c_str();
        key[pPtr[0] - 'a']++;
        maxKey[pPtr[0] - 'a']++;
        for (int i = 1; pPtr[i] != '\0'; i++) {
            int charNum = pPtr[i] - 'a';
            for (int j = 0; j < 26; j++) {
                if ((j + key[j]) % 26 == charNum) {
                    key[j]++;
                    maxKey[j] = max(maxKey[j], key[j]);
                } else {
                    key[j] = (j == charNum) ? 1 : 0;
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < 26; i++) {
            sum += maxKey[i];
        }
        return sum;
    }
};
