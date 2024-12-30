class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int min_len = min(word1.length(), word2.length());
        string res = "";
        for(int i = 0; i < min_len; i++){
            res += word1[i];
            res += word2[i];
        }

        return res + word1.substr(min_len) + word2.substr(min_len);
    }
};