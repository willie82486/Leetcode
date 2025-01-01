class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int len = s.length();
        string tmp_s = s;
        for(auto operation: shift){
            if(operation[0] == 0){
                for(int i = 0; i < len; i++){
                    int new_idx = i - operation[1];
                    while(new_idx < 0) new_idx += len;
                    tmp_s[new_idx] = s[i];
                }
            }
            else{
                for(int i = 0; i < len; i++){
                    int new_idx = i + operation[1];
                    while(new_idx >= len) new_idx %= len;
                    tmp_s[new_idx] = s[i];
                }
            }
            s = tmp_s;
        }
        return s;
    }
};