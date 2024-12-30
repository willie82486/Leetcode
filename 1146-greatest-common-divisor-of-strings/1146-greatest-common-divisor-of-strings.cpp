class Solution {
public:
    int GCD(int a, int b){
        return b == 0 ? a : GCD(b, a%b);
    }

    string gcdOfStrings(string str1, string str2) {
        if(str1 + str2 != str2 + str1) return "";

        int str1_len = str1.length();
        int str2_len = str2.length();
        int gcd_len = GCD(str1_len, str2_len);

        return str1.substr(0, gcd_len);
    }
};