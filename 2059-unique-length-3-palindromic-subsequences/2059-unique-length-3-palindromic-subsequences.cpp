class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int len = s.length();
        vector<int> first(26, -1);
        vector<int> last(26, -1);

        for(int i = 0; i < len; i++){
            int num = s[i] - 'a';
            if(first[num] == -1) first[num] = i;
            else last[num] = i;
        }

        int ans = 0;
        for(int i = 0; i < 26; i++){
            unordered_set<char> between;
            for(int j = first[i] + 1; j < last[i]; j ++){
                between.insert(s[j]);
            }
            ans += between.size();
        }

        return ans;
    }
};