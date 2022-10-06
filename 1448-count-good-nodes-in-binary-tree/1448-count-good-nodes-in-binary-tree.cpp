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
    void solve(TreeNode* root, int rootVal){
        if(root == nullptr) return;
        rootVal = max(rootVal, root->val);
        if(root->val >= rootVal){
            ++ans;
        }
        if(root->left) solve(root->left, rootVal);
        if(root->right) solve(root->right, rootVal);
    }
    
    int goodNodes(TreeNode* root) {
        solve(root, root->val);
        return ans;
    }
};