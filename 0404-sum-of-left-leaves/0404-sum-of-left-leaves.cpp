/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    void solve(TreeNode* root, int flag){
        if(!root) return;
        if(flag == 1 && !root->left && !root->right) ans += root->val;
        solve(root->left, 1);
        solve(root->right, 0);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        solve(root, -1);
        return ans;
    }
};