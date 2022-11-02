class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> st{bank.begin(), bank.end()};
        
        if(!st.count(end)) return -1;
        
        queue<string> Q;
        Q.push(start);
        int steps = 0;
        
        while(Q.size()){
            int sz = Q.size();
            while(sz--){
                string cur = Q.front();
                if(cur == end) return steps;
                st.erase(cur);
                Q.pop();
                
                for(int i = 0; i < 8; i++){
                    string tmp = cur;
                    for(char x: "ACGT"){
                        tmp[i] = x;
                        if(st.count(tmp)){
                            Q.push(tmp);
                        }
                    }
                }
            }
            ++steps;
        }
        return -1;
    }
};