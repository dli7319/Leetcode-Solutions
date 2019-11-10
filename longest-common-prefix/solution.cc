class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        stringstream sr;
        int char_pt = 0;
        while (true) {
            char a = NULL;
            for (int i = 0; i < strs.size(); i++) {
                if (char_pt == strs[i].length()) {
                    return sr.str();
                }
                if (i == 0) {
                    a = strs[i].at(char_pt);
                } else if (strs[i].at(char_pt) != a) {
                    return sr.str();
                }
            }
            sr << a;
            char_pt++;
        }
    }
};
