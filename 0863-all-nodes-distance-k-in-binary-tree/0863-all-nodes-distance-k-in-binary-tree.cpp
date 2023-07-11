/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    unordered_map<TreeNode*, TreeNode*> mp;
    
    void addParent(TreeNode* root, TreeNode* parent) {
        if(!root) return;
        if(!parent) parent = root;
        else mp[root] = parent;
        
        addParent(root->left, root);
        addParent(root->right, root);
    }
    
    void getDistanceKelements(TreeNode* root, TreeNode* target, int k){
        int cnt = 0;
        set<TreeNode*> st;
        queue<TreeNode*> que;
        que.push(target);
        
        while(!que.empty()){
            int sz = que.size();
            if(cnt > k) break;
            
            while(sz--){
                auto node = que.front();
                que.pop();
                
                if(node->left && !st.count(node->left)){
                    que.push(node->left);
                    st.insert(node->left);
                }
                
                if(node->right && !st.count(node->right)){
                    que.push(node->right);
                    st.insert(node->right);
                }
                
                if(mp.count(node) && !st.count(mp[node])){
                    que.push(mp[node]);
                    st.insert(mp[node]);
                }
                
                st.insert(node);
                
                if(cnt == k){
                    ans.push_back(node->val);
                }
            }
            ++cnt;
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        addParent(root, NULL);
        getDistanceKelements(root, target, k);
        
        return ans;
    }
};

