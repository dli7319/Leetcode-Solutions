class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0;
        int r = s.length()-1;
        int deletions = 0;
        int deletion_l = 0;
        int deletion_r = 0;
        while (l < r) {
            int l_letter = s.at(l) - 'a';
            int r_letter = s.at(r) - 'a';
            bool l_is_letter = l_letter >= 0 && l_letter < 26;
            bool r_is_letter = r_letter >= 0 && r_letter < 26;
            if (!l_is_letter) {
                l++;
            } else if (!r_is_letter) {
                r--;
            } else if (r_letter == l_letter) {
                l++;
                r--;
            } else {
                if (deletions <= 0) {
                    deletion_l = l;
                    deletion_r = r;
                    r--;
                    deletions++;
                } else if (deletions <= 1) {
                    l = deletion_l;
                    r = deletion_r;
                    l++;
                    deletions++;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
