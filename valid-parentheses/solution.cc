class Solution {
public:
    bool isValid(string s) {
        vector<char> openings{'(', '{', '['};
        vector<char> closings{')', '}', ']'};
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            char c = s.at(i);
            auto open = std::find(openings.begin(), openings.end(), c);
            auto close = std::find(closings.begin(), closings.end(), c);
            if (open != openings.end()) {
                st.push(*open);
            } else if (close != closings.end()) {
                if (st.empty()) {
                    return false;
                }
                int idx = std::distance(closings.begin(), close);
                char tip = st.top();
                if (tip != openings[idx]) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};
