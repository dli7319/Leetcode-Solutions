class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> final_code;
        bool in_comment = false;
        string prev_line = "";
        for (int i = 0; i < source.size(); i++) {
            string raw_line = source[i];
            string current_line = prev_line;
            int start = in_comment ? -1 : 0;
            for (int j = 0; j < raw_line.length() && j >= 0; j++) {
                if (in_comment) {
                    if (j > 0 && raw_line.at(j-1) == '*' && raw_line.at(j) == '/') {

                        in_comment = false;
                        if (j+1 < raw_line.length()) {
                            start = j+1;
                            if (raw_line.at(j+1) == '/' || raw_line.at(j+1) == '*') {
                                j++;
                            }
                        }
                    }
                } else {
                    if (j > 0 && raw_line.at(j-1) == '/' && raw_line.at(j) == '/') {
                        if (j-1 > start && start >= 0) {
                            current_line += raw_line.substr(start, j-1-start);
                        }
                        start = -1;
                        j=-99;
                    } else if (j > 0 && raw_line.at(j-1) == '/' && raw_line.at(j) == '*') {
                        in_comment = true;
                        if (j-1 > start && start >= 0) {
                            current_line += raw_line.substr(start, j-1-start);
                        }
                        j++;
                        start = -1;
                    }
                }
            }
            if (!in_comment && start >= 0) {
                current_line += raw_line.substr(start, raw_line.length()-start);
            }

            if (!in_comment && current_line.length() > 0) {
                final_code.push_back(current_line);
            }
            if (in_comment) {
                prev_line = current_line;
            } else {
                prev_line = "";
            }
        }
        return final_code;
    }
};
