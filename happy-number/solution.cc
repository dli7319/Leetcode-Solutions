class Solution {
public:
    bool isHappy(int n) {
        int num = n;
        int sum = 0;
        unordered_set<int> seen;
        while (num != 1) {
            if (seen.find(num) != seen.end()) {
                return false;
            }
            seen.insert(num);
            while (num > 0) {
                sum += pow(num % 10, 2);
                num /= 10;
            }
            num = sum;
            sum = 0;
        }
        return true;
    }
};
