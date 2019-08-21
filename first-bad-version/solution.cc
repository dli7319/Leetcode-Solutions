// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        uint first = 1;
        uint last = n;
        while (first < last - 1) {
            uint middle = (first + last) / 2;
            if (isBadVersion(middle)) {
                last = middle;
            } else {
                first = middle;
            }
        }
        return isBadVersion(first) ? first : last;
    }
};
