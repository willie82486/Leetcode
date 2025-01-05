class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diffArray(n, 0); 
        for (auto shift : shifts) {
            if (shift[2] == 1) {        
                diffArray[shift[0]]++; 
                if (shift[1] + 1 < n) {
                    diffArray[shift[1] + 1]--;
                }
            } else {
                diffArray[shift[0]]--;
                if (shift[1] + 1 < n) {
                    diffArray[shift[1] + 1]++;
                }
            }
        }

        int currentShift = 0;
        for (int i = 0; i < n; i++) {
            currentShift = (currentShift + diffArray[i]) % 26;
            s[i] = 'a' + (s[i] - 'a' + currentShift + 26) % 26; 
        }

        return s;

    } 
};