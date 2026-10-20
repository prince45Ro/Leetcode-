class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();
        deque<int> dq;

        // First putting k-1 elements in deque
        for (int i = 0; i < k - 1; i++) {
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        vector<int> ans;

        for (int i = k - 1; i < n; i++) {
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);  

            if (dq.front() <= i - k) {
                dq.pop_front();
            }

            ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};