class Solution {
public:
    int compress(vector<char>& chars) {
        auto it = chars.begin();
        auto next = it;
        while (it != chars.end() && (it+1) != chars.end()) {
            next = it+1;
            int ct = 0;
            while(next != chars.end() && *it == *next) {
                ct++;
                next++;
            }
            if (ct > 0) {
                auto s = to_string(ct + 1);
                for (int i = 0; i < s.length(); i++) {
                    *(++it) = s.at(i);
                }
                if (it+1 != next) {
                    chars.erase(it+1, next);
                }
            }
            it++;
        }
        return chars.size();
    }
};
