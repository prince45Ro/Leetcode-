class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
            sort(nums.begin(), nums.end());

    int n = nums.size();
    int closestSum = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < n - 2; i++) {

        int start = i + 1;
        int end = n - 1;

        while (start < end) {

            int sum = nums[i] + nums[start] + nums[end];

            if (abs(target - sum) < abs(target - closestSum)) {
                closestSum = sum;
            }

            if (sum == target) {
                return sum;
            }
            else if (sum < target) {
                start++;
            }
            else {
                end--;
            }
        }
    }

    return closestSum;

        
    }
};