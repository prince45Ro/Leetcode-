class Solution {
public:
    vector<string> validStrings(int n) {

           vector<string> ans;
    queue<string> q;

    q.push("1");
    q.push("0");

    while (!q.empty()) {
        string temp = q.front();
        q.pop();

        if (temp.size() == n) {
            ans.push_back(temp);
            continue;
        }

        q.push(temp + '1');

        if (temp.back() != '0') {
            q.push(temp + '0');
        }
    }

    return ans;

    }
};