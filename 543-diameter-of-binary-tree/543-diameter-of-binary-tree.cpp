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
    int mx = 0;
    int solve(TreeNode* root, int depth){
        if(!root) return 0;
        int leftTree = solve(root->left, depth);
        int rightTree = solve(root->right, depth);
        
        mx = max(mx, leftTree + rightTree);
        return max(leftTree, rightTree) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int ans = solve(root, 0);
        
        return mx;
    }
};