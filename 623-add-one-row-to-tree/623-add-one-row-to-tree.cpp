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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        
        int cntDepth = 1;
        queue<TreeNode*> Q;
        Q.push(root);
        
        while(Q.size()){
            int sz = Q.size();
            for(int i = 0; i < sz; i++){
                auto cur = Q.front();
                Q.pop();
                
                if(cntDepth == depth - 1){
                    TreeNode* firstNode = new TreeNode(val);
                    TreeNode* secondNode = new TreeNode(val);
                    
                    firstNode->left = cur->left;
                    secondNode->right = cur->right;
                    
                    cur->left = firstNode;
                    cur->right = secondNode;
                } else {
                    if(cur->left) Q.push(cur->left);
                    if(cur->right) Q.push(cur->right);
                }
            }
            if(cntDepth >= depth - 1) break;
            ++cntDepth;
        }
        return root;
    }
};