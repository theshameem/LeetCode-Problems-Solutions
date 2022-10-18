class Solution {
public:
    string addStrings(string num1, string num2) {
        int sum = 0, i = num1.size() - 1, j = num2.size() - 1;
        string ans = "";
        
        while(i >= 0 && j >= 0){
            sum += ((num1[i--] - '0') + (num2[j--] - '0'));
            ans += (char(sum % 10 + '0'));
            sum /= 10;
        }
        
        while(i >= 0){
            sum += (num1[i--] - '0');
            ans += char(char(sum % 10 + '0'));
            sum /= 10;
        }
        
        while(j >= 0){
            sum += (num2[j--] - '0');
            ans += char(char(sum % 10 + '0'));
            sum /= 10;
        }
        if(sum > 0) ans += char(sum % 10 + '0');
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};