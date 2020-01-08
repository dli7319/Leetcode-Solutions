class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int removes = 0;
        int openings = 0;
        string new_str = "";
        for (int i = 0; i < s.length(); i++) {
            if (s.at(i) == '(') {
                openings++;
            }
            if (s.at(i) == ')') {
                openings--;
            }
            if (openings < 0) {
                removes++;
                openings = 0;
            } else {
                new_str.push_back(s.at(i));
            }
        }
        removes = 0;
        openings = 0;
        string new_str2 = "";
        for (int i = new_str.length()-1; i >= 0; i--) {
            if (new_str.at(i) == '(') {
                openings--;
            }
            if (new_str.at(i) == ')') {
                openings++;
            }
            if (openings < 0) {
                removes++;
                openings = 0;
            } else {
                new_str2.push_back(new_str.at(i));
            }
        }
        std::reverse(new_str2.begin(), new_str2.end());
        return new_str2;
    }
};
