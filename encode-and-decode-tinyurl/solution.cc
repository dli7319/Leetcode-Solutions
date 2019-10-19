class Solution {
public:

    vector<string> s;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        s.push_back(longUrl);
        return to_string(s.size() - 1);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int c = stoi(shortUrl);
        if (c < s.size()) {
            return s[c];
        }
        return string();
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
