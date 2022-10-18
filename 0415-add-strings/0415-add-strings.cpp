class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0;
        vector<int> v;
        while(num1.size() && num2.size()){
            int x = num1.back() - '0';
            int y = num2.back() - '0';
            v.push_back((x + y + carry) % 10);
            carry = (x + y + carry) / 10;
            
            num1.pop_back();
            num2.pop_back();
        }
        
        while(num1.size()){
            int x = num1.back() - '0';
            v.push_back((x + carry) % 10);
            carry = (x + carry) / 10;
            
            num1.pop_back();
        }
        
        while(num2.size()){
            int x = num2.back() - '0';
            v.push_back((x + carry) % 10);
            carry = (x + carry) / 10;
            
            num2.pop_back();
        }
        if(carry) v.push_back(carry);
        
        reverse(v.begin(), v.end());
        
        string ans = "";
        
        for(auto i: v) ans += to_string(i);
        
        return ans;
    }
};