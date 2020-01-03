class Solution {
public:
    string addBinary(string a, string b) {
        ostringstream ans;
        int posA = a.length()-1;
        int posB = b.length()-1;
        int carry = 0;
        while(posA >= 0 || posB >= 0) {
            if (posA >= 0 && a.at(posA) - '0') {
                carry++;
            }
            if (posB >= 0 && b.at(posB) - '0') {
                carry++;
            }
            if (carry % 2) {
                ans << "1";
            } else {
                ans << "0";
            }
            carry /= 2;
            posA--;
            posB--;
        }
        if (carry % 2) {
            ans << "1";
        }
        string an = ans.str();
        std::reverse(an.begin(), an.end());
        return an;
    }
};
