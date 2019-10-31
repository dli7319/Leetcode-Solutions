class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> new_digits(digits);
        int carry = 1;
        for (int i = new_digits.size()-1; i >= 0; i--) {
            int nd = carry + new_digits[i];
            new_digits[i] = nd % 10;
            carry = nd / 10;
            if (carry == 0)
                return new_digits;
        }
        if (carry > 0) {
            new_digits.insert(new_digits.begin(), carry);
        }
        return new_digits;
    }
};
