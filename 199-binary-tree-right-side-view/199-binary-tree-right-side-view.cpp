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
    void solve(TreeNode* root){
        if(!root) return;
        ans.push_back(root->val);
        if(root->right) solve(root->right);
        else if(root->left) solve(root->left);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return ans;
        
        queue<TreeNode*> Q;
        Q.push(root);
        
        while(Q.size()){
            int sz = Q.size();
            for(int i = 0; i < sz; i++){
                auto curr = Q.front();
                Q.pop();
                if(i == 0) ans.push_back(curr->val);
                if(curr->right) Q.push(curr->right);
                if(curr->left) Q.push(curr->left);
            }
        }
        return ans;
    }
};