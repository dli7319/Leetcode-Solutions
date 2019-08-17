class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // Probably would be faster using a vector and just manipulating the last three elements.
        list<string> tokList;
        std::copy( tokens.begin(), tokens.end(), std::back_inserter( tokList ) );
        list<string>::iterator it = tokList.begin();
        if (tokList.size() == 1) {
            return stoi(tokList.front());
        }
        string one = *(it++);
        string two = *(it++);
        string three = *it;

        while(tokList.size() > 1) {
            if (three == "+") {
                int val = stoi(one) + stoi(two);
                it--; it--;
                tokList.insert(it, to_string(val));
                tokList.erase(it++);
                tokList.erase(it++);
                tokList.erase(it--);
                if ( it != tokList.begin()) {
                    it--;
                }
                if (tokList.size() >= 3) {
                    one = *(it++);
                    two = *(it++);
                    three = *it;
                }
            } else if (three == "-") {
                int val = stoi(one) - stoi(two);
                it--; it--;
                tokList.insert(it, to_string(val));
                tokList.erase(it++);
                tokList.erase(it++);
                tokList.erase(it--);
                if ( it != tokList.begin()) {
                    it--;
                }
                if (tokList.size() >= 3) {
                    one = *(it++);
                    two = *(it++);
                    three = *it;
                }
            } else if (three == "*") {
                int val = stoi(one) * stoi(two);
                it--; it--;
                tokList.insert(it, to_string(val));
                tokList.erase(it++);
                tokList.erase(it++);
                tokList.erase(it--);
                if ( it != tokList.begin()) {
                    it--;
                }
                if (tokList.size() >= 3) {
                    one = *(it++);
                    two = *(it++);
                    three = *it;
                }
            } else if (three == "/") {
                int val = stoi(one) / stoi(two);
                it--; it--;
                tokList.insert(it, to_string(val));
                tokList.erase(it++);
                tokList.erase(it++);
                tokList.erase(it--);
                if ( it != tokList.begin()) {
                    it--;
                }
                if (tokList.size() >= 3) {
                    one = *(it++);
                    two = *(it++);
                    three = *it;
                }
            } else {
                one = two;
                two = three;
                three = *(++it);
            }
        }
        return stoi(tokList.front());
    }
};
