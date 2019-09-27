class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> final_vec{0};
        for (int i = 1; i <= num; i++) {
            // my_bit is the largest bit only
            int my_bit = 1;
            int original_2 = i/2;
            while (my_bit <= original_2) {
                my_bit = my_bit << 1;
            }
            int lesser_num = i & (~my_bit);
            final_vec.push_back(1 + final_vec[lesser_num]);
        }
        return final_vec;
    }
};
