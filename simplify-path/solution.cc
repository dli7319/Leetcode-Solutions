class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        bool done = false;
        int last_pos = -1;
        while (!done) {
            last_pos = path.find("/", last_pos + 1);
            if (last_pos != string::npos) {
                int next_pos = path.find("/", last_pos + 1);
                string substr = path.substr(last_pos + 1, next_pos - last_pos - 1);
                cout << "Next:" << substr << endl;
                if (substr == "" || substr == ".") {

                } else if (substr == "..") {
                    if (!st.empty()) {
                        st.pop_back();
                    }
                } else {
                    st.push_back(substr);
                }
            }
            done = last_pos == string::npos;
        }
        string ans = "/";
        for (int i = 0; i < st.size(); i++) {
            if (ans.at(ans.size()-1) != '/') {
                ans = ans + "/";
            }
            ans = ans + st[i];
        }
        return ans;
    }
};
