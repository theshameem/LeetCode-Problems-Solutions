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
    void traverse(TreeNode* root, vector<int> &v){
        if(!root) return;
        traverse(root->left, v);
        v.push_back(root->val);
        traverse(root->right, v);
    }
    
    void merge(vector<int> left, vector<int> right, vector<int> &ans){
        for(int i = 0, j = 0; ans.size() < left.size() + right.size(); ){
            if(i == left.size()) ans.push_back(right[j++]);
            else if(j == right.size()) ans.push_back(left[i++]);
            else if(left[i] <= right[j]) ans.push_back(left[i++]);
            else ans.push_back(right[j++]);
        }
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> left, right, ans;
        traverse(root1, left);
        traverse(root2, right);
        merge(left, right, ans);
        return ans;
    }
};