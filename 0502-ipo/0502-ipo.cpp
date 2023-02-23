class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects;
        
        for(int i = 0; i < n; i++){
            projects.push_back({capital[i], profits[i]});
        }
        sort(projects.begin(), projects.end());
        
        priority_queue<int> Q;
        int ptr = 0;
        
        for(int i = 0; i < k; i++){
            while(ptr < n && projects[ptr].first <= w){
                Q.push(projects[ptr++].second);
            }
            if(Q.empty()){
                break;
            }
            w += Q.top();
            Q.pop();
        }
        return w;
    }
};
