class Solution {
public:
    string convert(string s, int numRows) {
        if (s == "") return "";
        if (numRows < 2) return s;
        string news = "";
        int rows = numRows;
        int skip = numRows + (numRows-2);
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < ((s.length() + skip-1) / skip) * (rows-1); j++) {
                if (j % (rows-1) == 0) {
                    int idx = (j / (rows-1)) * skip + i;
                    if (idx < s.length()) {
                        news.push_back(s.at(idx));
                        // cout << "i,j" << i << ", " << j << " " << s.at(idx) << endl;
                    }
                } else if (j % (rows-1) == (rows-1-i)) {
                    int idx = (j / (rows-1)) * skip + rows + (rows - 2 - i);
                    if (idx < s.length()) {
                        news.push_back(s.at(idx));
                        // cout << "i,j" << i << ", " << j << " " << s.at(idx) << endl;
                    }
                }
            }
        }
        return news;
    }
};
