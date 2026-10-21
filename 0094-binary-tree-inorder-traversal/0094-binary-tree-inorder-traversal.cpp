/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root) {
            return ans;
        }
        stack<TreeNode*> s;
        s.push(root);
        stack<bool> trav;
        trav.push(0);

        while (!s.empty()) {

            TreeNode* temp = s.top();
            s.pop();
            int val = trav.top();
            trav.pop();

            if (val) {
                ans.push_back(temp->val);
            } else {
                if (temp->right) {
                    s.push(temp->right);
                    trav.push(0);
                }
                s.push(temp);
                trav.push(1);
                if (temp->left) {
                    s.push(temp->left);
                    trav.push(0);
                }
            }
        }
        return ans;
    }
};