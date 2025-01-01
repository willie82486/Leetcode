class Solution {
public:
    int maxScore(string s) {
        int len = s.length();
        int leftZero = 0;
        int rightOne = 0;
        int maxScore = 0;
        for(char c: s){
            if(c == '1') rightOne++;
        }
        if(rightOne == len || rightOne == 0) return len - 1;

        for(int i = 0; i < len - 1; i++){
            if(s[i] == '0') leftZero++;
            else rightOne--;
            maxScore = max(maxScore, leftZero + rightOne);
        }
        return maxScore;
    }
};