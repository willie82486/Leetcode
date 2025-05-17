class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int res = 0;
        int left = 0;
        int right = nums.size() - 1;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] > nums[mid + 1]){
                right = mid;
                res = right;
            }
            else{
                left = mid + 1;
                res = left;
            }
        }
        return res;
    }
};