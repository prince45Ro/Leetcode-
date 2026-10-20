class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
          if (matrix.empty()) return 0;

    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> heights(m, 0);
    int ans = 0;

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == '1') {
                heights[j]++;
            } else {
                heights[j] = 0;
            }
        }

        stack<int> st;
        vector<int> NSL(m, -1);
        vector<int> NSR(m, m);

        // Next Smaller Right
        for (int j = 0; j < m; j++) {
            while (!st.empty() && heights[st.top()] > heights[j]) {
                NSR[st.top()] = j;
                st.pop();
            }
            st.push(j);
        }

        while (!st.empty()) st.pop();

        // Next Smaller Left
        for (int j = m - 1; j >= 0; j--) {
            while (!st.empty() && heights[st.top()] > heights[j]) {
                NSL[st.top()] = j;
                st.pop();
            }
            st.push(j);
        }

        // Calculate maximum rectangle
        for (int j = 0; j < m; j++) {
            int width = NSR[j] - NSL[j] - 1;
            int area = heights[j] * width;
            ans = max(ans, area);
        }
    }

    return ans;



    }
};