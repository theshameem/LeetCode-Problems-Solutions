class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i = 0; i < flowerbed.size() && n > 0; i++){
            if(flowerbed[i] == 0){
                bool leftEmpty = (i == 0) || (flowerbed[i - 1] == 0);
                bool rightEmpty = (i == flowerbed.size() - 1) || (flowerbed[i + 1] == 0);
                
                if(leftEmpty && rightEmpty){
                    flowerbed[i] = 1;
                    --n;
                }
            }
        }
        return n == 0;
    }
};