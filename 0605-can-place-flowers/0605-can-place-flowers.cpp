class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt = 0;
        int size = flowerbed.size();
        if(size == 1){
            if(flowerbed[0] == 0 && n <= 1) return true;
            else if(flowerbed[0] == 1 && n == 0) return true;
            return false;
        } 
        for(int i = 0; i < size; i++){
            if(i == 0){
                if(flowerbed[i + 1] == 0 && flowerbed[i] != 1){
                    flowerbed[i] = 1;
                    cnt++;
                }
            }
            else if(i == size - 1){
                if(flowerbed[i - 1] == 0 && flowerbed[i] != 1){
                    flowerbed[i] = 1;
                    cnt++;
                }
            }
            else{
                if(flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0 && flowerbed[i] != 1){
                    flowerbed[i] = 1;
                    cnt++;
                }
            }
        }

        if(cnt >= n) return true;
        else return false;
    }
};