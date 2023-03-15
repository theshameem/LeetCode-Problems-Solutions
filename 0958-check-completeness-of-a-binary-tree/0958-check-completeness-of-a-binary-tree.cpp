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
    int countNodes(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    
    bool DFS(TreeNode* node, int idx, int n){
        if(node == NULL) return true;
        if(idx >= n) return false;
        
        return DFS(node->left, 2 * idx + 1, n) &&
               DFS(node->right, 2 * idx + 2, n);
    }
    
    bool isCompleteTree(TreeNode* root) {
        return DFS(root, 0, countNodes(root));
    }
};