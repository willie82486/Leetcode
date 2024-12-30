class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        map<int, int> dif_map;
        vector<int> res;
        int left = 0;
        int right = size -1;
        for(int i = 0; i < size; i++){
            if(dif_map.find(target - nums[i]) != dif_map.end()){
                res.push_back(dif_map[target - nums[i]]);
                res.push_back(i);
            }
            else{
                dif_map.insert({nums[i], i});
            }
        }
        return res;
    }
};