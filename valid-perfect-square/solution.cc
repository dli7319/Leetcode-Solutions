class Solution {
public:
    bool isPerfectSquare(int num) {
        uint i = 0;
        while (i * i < num) {
            i++;
        }
        if (i * i == num) {
            return true;
        }
        return false;
    }
};
