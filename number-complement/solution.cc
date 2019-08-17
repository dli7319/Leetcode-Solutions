class Solution {
public:
    int findComplement(int num) {
        int cpy = num;
        int mask = 0;
        while(cpy > 0) {
            cpy = cpy >> 1;
            mask = (mask<<1) | 1;
        }
        return (~num) & mask;
    }
};
