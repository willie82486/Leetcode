class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int len = s.length();
        unordered_set<char> letters;
        for(char c: s){
            letters.insert(c);
        }

        int ans = 0;
        for(char letter: letters){
            int first = -1;
            int second = -1;
            for(int i = 0; i < len; i++){
                if(s[i] == letter){
                    if(first == -1) first = i;
                    else second = i;
                }
            }

            unordered_set<char> between;
            for(int i = first + 1; i < second; i++){
                between.insert(s[i]);
            }

            ans += between.size();
        }

        return ans;
    }
};