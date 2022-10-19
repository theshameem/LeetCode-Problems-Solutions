class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for(int i = 0; i < n; i++){
            int val = i + 1;
            if(val % 3 == 0 && val % 5 == 0){
                ans.push_back("FizzBuzz");
            } else if(val % 3 == 0){
                ans.push_back("Fizz");
            } else if(val % 5 == 0){
                ans.push_back("Buzz");
            } else {
                ans.push_back(to_string(val));
            }
        }
        return ans;
    }
};