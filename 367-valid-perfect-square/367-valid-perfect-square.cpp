class Solution {
public:
    bool isPerfectSquare(int num) {
        long long int x = 2;
        while(x <= num){
            if(x * x == num) return true;
            else if(x * x > num) return false;
            x++;
        }
        return true;
    }
};