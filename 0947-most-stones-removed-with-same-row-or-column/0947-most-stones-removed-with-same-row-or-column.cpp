class Solution {
public:
    int parent[100000];
    void makeUnion(int u, int v){
        int uParent = findParent(u);
        int vParent = findParent(v);
        parent[uParent] = vParent;
    }
    
    int findParent(int n){
        if(parent[n] == n) return n;
        return parent[n] = findParent(parent[n]);
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int mxRow = 0, mxCol = 0;
        for(auto i: stones){
            mxRow = max(mxRow, i[0]);
            mxCol = max(mxCol, i[1]);
        }
        for(int i = 0; i <= mxRow + mxCol + 5; i++) parent[i] = i;
        
        unordered_map<int, int> stoneNodes;
        for(auto it: stones){
            int nodeRow = it[0];
            int nodeCol = it[1] + mxRow + 1;
            makeUnion(nodeRow, nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }
        
        int cnt = 0;
        for(auto it: stoneNodes){
            if(findParent(it.first) == it.first) ++cnt;
        }
        
        return n - cnt;
    }
};