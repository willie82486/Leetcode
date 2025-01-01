class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int size = nums.size();
        double sum = 0.0;
        double avg = 0.0;
        for(int i = 0; i < k; i++){
            sum += nums[i];
        }
        avg = sum / k;

        if(size == k) return avg;

        for(int i = k; i < size; i++){
            sum = sum - nums[i - k] + nums[i];
            avg = max(avg, sum / k);
        }
        return avg;
    }
};