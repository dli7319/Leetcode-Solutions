class Solution {
public:
    int romanToInt(string s) {
        int start_idx = 0;
        int current = 0;
        while (start_idx < s.length()) {
            char my_char = s.at(start_idx);
            char next_char = start_idx + 1 < s.length() ?
                s.at(start_idx+1) :
                '\0';
            switch(my_char) {
                case 'I':
                    if (next_char == 'V') {
                        current += 4;
                        start_idx++;
                    } else if (next_char == 'X') {
                        current += 9;
                        start_idx++;
                    } else {
                        current++;
                    }
                    break;
                case 'V':
                    current += 5;
                    break;
                case 'X':
                   if (next_char == 'L') {
                        current += 40;
                        start_idx++;
                    } else if (next_char == 'C') {
                        current += 90;
                        start_idx++;
                    } else {
                        current+=10;
                    }
                    break;
                case 'L':
                    current += 50;
                    break;
                case 'C':
                  if (next_char == 'D') {
                        current += 400;
                        start_idx++;
                    } else if (next_char == 'M') {
                        current += 900;
                        start_idx++;
                    } else {
                        current += 100;
                    }
                    break;
                case 'D':
                    current += 500;
                    break;
                case 'M':
                    current += 1000;
                    break;
            }
            start_idx++;
        }
        return current;
    }
};
