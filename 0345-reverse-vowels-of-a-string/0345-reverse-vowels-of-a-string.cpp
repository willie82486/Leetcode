class Solution {
public:
    string reverseVowels(string s) {
        int left_idx = 0;
        int right_idx = s.length() - 1;
        string vowels = "aeiouAEIOU";
        while(left_idx < right_idx){
            while(left_idx < right_idx && vowels.find(s[left_idx]) == string::npos){
                left_idx++;
            }
            while(left_idx < right_idx && vowels.find(s[right_idx]) == string::npos){
                right_idx--;
            }     
            swap(s[left_idx], s[right_idx]);
            left_idx++;
            right_idx--;
        }
        return s;
    }
};