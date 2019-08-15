class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string reversedStr;
        int addedChars = 0;
        for (int i = 0; i < S.length(); i++) {
            int pos = S.length() - i - 1;
            char posChar = S.at(pos);
            if (posChar != '-') {
                if (addedChars > 0 && addedChars % K == 0) {
                    reversedStr.push_back('-');
                }
                addedChars++;
                bool isLetter = true;
                int offset = posChar - 'a';
                if (offset < 0 || offset > 25) {
                    offset = posChar - 'A';
                }
                if (offset < 0 || offset > 25) {
                    offset = posChar - '0';
                    isLetter = false;
                }

                if (isLetter) {
                    reversedStr.push_back(offset + 'A');
                } else {
                    reversedStr.push_back(offset + '0');
                }
            }
        }
        string unreversedStr;
        for (int i = reversedStr.length() - 1; i >= 0; i--) {
            unreversedStr.push_back(reversedStr.at(i));
        }
        return unreversedStr;
    }
};
