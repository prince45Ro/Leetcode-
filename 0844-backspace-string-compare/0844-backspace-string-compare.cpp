class Solution {
public:
     string backspace(string &str) {
        string ans;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] != '#') {
                ans.push_back(str[i]);

            } else {
                if (!ans.empty()) {
                    ans.pop_back();
                }
            }
        }
        return ans;
    }

    bool backspaceCompare(string s, string t) {
        return backspace(s) == backspace(t);
    }
};