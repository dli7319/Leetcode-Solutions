class Solution {
public:
    string intToRoman(int num) {
        string result;
        int num_M = num / 1000;
        result += std::string(num_M, 'M');
        num -= num_M * 1000;
        if (num / 100 == 9) {
            result += "CM";
            num -= 900;
        } else {
            int num_C = num / 100;
            if (num_C >= 5) {
                result += "D";
                num -= 500;
                num_C -= 5;
            }
            if (num_C == 4) {
                result += "CD";
                num -= 400;
                num_C -= 4;
            }
            result += std::string(num_C, 'C');
            num -= 100 * num_C;
        }
        if (num / 10 == 9) {
            result += "XC";
            num -= 90;
        } else {
            int num_X = num / 10;
            if (num_X >= 5) {
                result += "L";
                num -= 50;
                num_X -= 5;
            }
            if (num_X == 4) {
                result += "XL";
                num -= 40;
                num_X -= 4;
            }
            result += std::string(num_X, 'X');
            num -= 10 * num_X;
        }
        if (num == 9) {
            result += "IX";
            num -= 900;
        } else {
            int num_I = num;
            if (num_I >= 5) {
                result += "V";
                num -= 5;
                num_I -= 5;
            }
            if (num_I == 4) {
                result += "IV";
                num -= 4;
                num_I -= 4;
            }
            result += std::string(num_I, 'I');
            num -= num_I;
        }
        return result;
    }
};
