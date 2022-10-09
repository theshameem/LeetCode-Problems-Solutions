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
    vector<int> ans;
    void solve(TreeNode* root, int level){
        if(!root) return;
        if(ans.size() < level) ans.push_back(root->val);
        if(root->right) solve(root->right, level + 1);
        if(root->left) solve(root->left, level + 1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return ans;
        solve(root, 1);
        return ans;
    }
};