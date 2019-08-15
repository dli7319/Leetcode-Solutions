class Solution {
public:
    vector<string> commonChars(vector<string>& A) {

        int finalCount[26];
        for (int i = 0; i < 26; i++) {
            finalCount[i] = INT_MAX;
        }
        for (string str : A) {
            int thisCharCount[26];
            for (int i = 0; i < 26; i++) {
                thisCharCount[i] = 0;
            }
            const char *strArr = str.c_str();
            for (int i = 0; strArr[i] != '\0'; i++) {
                thisCharCount[strArr[i] - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                finalCount[i] = finalCount[i] < thisCharCount[i] ?
                    finalCount[i] : thisCharCount[i];
            }
        }


        vector<string> finalCharacters;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < finalCount[i]; j++) {
                finalCharacters.push_back(string(1, 'a' + i));
            }
        }
        return finalCharacters;
    }
};
