class Solution {
public:
    long long countHour(vector<int>& piles, int k){
        long long hour = 0;
        for(auto pile: piles){
            hour += pile / k + (pile % k != 0);
        }
        return hour;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end(), less<int>());
        int left = 1;
        int right = piles[piles.size()-1];
        while(left <= right){
            int mid = left + (right - left) / 2;
            long long  hour = countHour(piles, mid);
            if(hour <= h){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }

        return left;
    }
};