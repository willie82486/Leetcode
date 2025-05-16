class Solution {
public:
    int binarySearch(int &spell, vector<int>& arr, int &arr_size, long long &success){
        int left = 0;
        int right = arr_size - 1;
        int resIdx = -1;

        while(left <= right){
            int mid = left + (right - left) / 2;
            long long num = (long long)spell * arr[mid];
            if(num < success){
                left = mid + 1;
            }
            else{
                resIdx = mid; 
                right = mid - 1;
            }
        }
        return resIdx;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(), potions.end());

        vector<int> ans;
        for(auto spell: spells){
            int idx = binarySearch(spell, potions, m, success);
            cout << idx << endl;
            if(idx == -1) ans.push_back(0);
            else ans.push_back(m - idx);
        }

        return ans;
    }
};