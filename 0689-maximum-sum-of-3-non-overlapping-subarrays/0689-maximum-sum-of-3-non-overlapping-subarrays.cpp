class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int nums_size = nums.size();
        int sums_size = nums_size - k + 1;
        vector<int> sums(sums_size);
        int first_element_of_sums = 0;
        for(int i = 0 ; i < k; i++){
            first_element_of_sums += nums[i];
        }
        sums[0] = first_element_of_sums;
        for(int i = k; i < nums_size; i++){
            sums[i - k + 1] = sums[i - k] -nums[i - k] + nums[i];
        }

        vector<vector<int>> memo(sums_size, vector<int>(4 , -1));
        vector<int> indices;

        dp(sums, k, 0, 3, memo);
        dfs(sums, k, 0, 3, memo, indices);
        
        return indices;
    }

private:
    int dp(vector<int>& sums, int k, int idx, int rem, vector<vector<int>>& memo){
        if(rem == 0) return 0;
        if(idx >= sums.size()) return 0;
        if(memo[idx][rem] != -1) return memo[idx][rem];

        int withCur = sums[idx] + dp(sums, k, idx + k, rem - 1, memo);
        int withoutCur = dp(sums, k, idx + 1, rem, memo);
        memo[idx][rem] = max(withCur, withoutCur);
        return memo[idx][rem];
    }

    void dfs(vector<int>& sums, int k, int idx, int rem, vector<vector<int>>& memo, vector<int>& indices){
        if(rem == 0) return;
        if(idx >= sums.size()) return;

        int withCur = sums[idx] + dp(sums, k, idx + k, rem - 1, memo);
        int withoutCur = dp(sums, k, idx + 1, rem, memo);
        if(withCur >= withoutCur){
            indices.push_back(idx);
            dfs(sums, k, idx + k, rem - 1, memo, indices);
        }
        else{
            dfs(sums, k, idx + 1, rem, memo, indices);
        }
    }
};