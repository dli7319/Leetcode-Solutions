class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.length()-1;
        while (l < r) {
            int l_letter = tolower(s.at(l)) - 'a';
            int r_letter = tolower(s.at(r)) - 'a';
            int l_number = s.at(l) - '0';
            int r_number = s.at(r) - '0';
            bool l_is_letter = l_letter >= 0 && l_letter < 26;
            bool l_is_number = l_number >= 0 && l_number < 10;
            bool r_is_letter = r_letter >= 0 && r_letter < 26;
            bool r_is_number = r_number >= 0 && r_number < 10;
            if (!l_is_letter && !l_is_number) {
                l++;
            } else if (!r_is_letter && !r_is_number) {
                r--;
            } else if (r_letter == l_letter || r_number == l_number) {
                l++;
                r--;
            } else {
                return false;
            }
        }
        return true;
    }
};
