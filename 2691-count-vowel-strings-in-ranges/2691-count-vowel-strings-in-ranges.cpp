class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int words_size = words.size();
        string vowel = "aeiou";

        vector<int> prefix(words.size() + 1, 0);
        int idx = 1;
        int cnt = 0;
        for(string s: words){
            if(vowel.find(s[0]) != string::npos && vowel.find(s[s.length() - 1]) != string::npos){
                cnt++;
            } 
            prefix[idx] = cnt;
            idx++;
        }

        vector<int> ans(queries.size());
        idx = 0;
        for(auto query: queries){
            int L = query[0];
            int R = query[1];
            ans[idx++] = (prefix[R + 1] - prefix[L]);
        }
        return ans;
    }
};