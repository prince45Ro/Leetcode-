class Solution {
public:
    void combination(vector<int>& nums, int index, int n, vector<int>& path,
                     vector<vector<int>>& ans, int target) {

        if (target == 0) {
            ans.push_back(path);
            return;
        }

        if (target < 0 || index == n) {
            return;
        }

        vector<bool> used(51, 0);
        for (int i = index; i < n; i++) {
            if (!used[nums[i]]) {
                used[nums[i]] = 1;
                path.push_back(nums[i]);
                combination(nums, i+1, n, path, ans, target - nums[i]);
                path.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> path;

        sort(candidates.begin(), candidates.end());

        combination(candidates, 0, candidates.size(), path, ans, target);

        return ans;
    }
};