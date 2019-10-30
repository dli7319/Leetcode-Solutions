class Solution {
public:
    string countAndSay(int n) {
        vector<string> memo = {"1"};
        while (memo.size() < n) {
            string last = memo.back();
            string new_entry = "";
            int count = 1;
            for (int i = 0; i < last.length(); i++) {
                if (i + 1 == last.length() || last.at(i) != last.at(i+1)) {
                    new_entry += to_string(count) + last.substr(i, 1);
                    count = 1;
                } else {
                    count++;
                }
            }
            memo.push_back(new_entry);
            // cout << new_entry << endl;
        }
        return memo[n-1];
    }
};
