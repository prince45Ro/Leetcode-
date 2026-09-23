class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int sub_sum = 0, max_sum = INT_MIN, n = nums.size();

        for (int i = 0; i < n; i++) {
            if (sub_sum < 0) {
                sub_sum = nums[i];

            } else {
                sub_sum += nums[i];
            }

            max_sum = max(max_sum, sub_sum);
        }
        return max_sum;
    }
};