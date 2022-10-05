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
    bool ans = false;
    int target;
    void solve(TreeNode* root, int sum){
        if(ans) return;
        if(!root){
            ans = false;
            return;
        }
        if(root->left == nullptr && root->right == nullptr){
            sum += root->val;
            if(sum == target){
                ans = true;
            }
        }
        if(root->left){
            solve(root->left, sum + root->val);
        }
        if(root->right){
            solve(root->right, sum + root->val);
        }
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        if(!root->left && !root->right && targetSum - root->val == 0) return true;
        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }
};