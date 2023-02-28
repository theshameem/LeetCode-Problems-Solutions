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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        map<string, vector<TreeNode*>> mp;
        vector<TreeNode*> ans;
        makeSerial(root, mp);
        
        for(auto it: mp){
            if(it.second.size() > 1){
                ans.push_back(it.second[0]);
            }
        }
        return ans;
    }
    
    string makeSerial(TreeNode* root, map<string, vector<TreeNode*>>& mp){
        if(!root) return "";
        string s= "(" + makeSerial(root->left, mp) + to_string(root->val) + makeSerial(root->right, mp) + ")";
        mp[s].push_back(root);
        return s;
    }
};