class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int copy = x;
        int64_t rev = 0;
        while (copy > 0) {
            rev *= 10;
            rev += copy % 10;
            copy /= 10;
        }
        return rev == x;
    }
};

