class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        return helper(s, 4);
    }

    vector<string> helper(string s, int sections) {
        if (sections <= 0 || s.empty()) return vector<string>();
        if (sections == 1) {
            if (s.length() > 3 ||
                (s.length() > 1 && s.at(0) == '0') ||
                (stoi(s) > 255)) {
                return vector<string>();
            }
            return vector<string>{s};
        }
        vector<string> res;
        for (int i = 1; i < 4; i++) {
            if (s.size() > i) {
                auto first = helper(s.substr(0, i), 1);
                auto second = helper(s.substr(i), sections-1);
                for (auto f : first) {
                    for (auto s : second) {
                        res.push_back(f + "." + s);
                    }
                }
            }
        }
        return res;
    }
};
