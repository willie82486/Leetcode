class Solution {
public:
    vector<int> minOperations(string boxes) {
        int len = boxes.length();
        vector<int> ans(len, 0);

        int ballsFormLeft = 0, movesFormLeft = 0;
        int ballsFormRight = 0, movesFormRight = 0;

        for (int i = 0; i < len; i++) {
            ans[i] += movesFormLeft;
            ballsFormLeft += boxes[i] - '0';
            movesFormLeft += ballsFormLeft;

            int j = len - 1 - i;
            ans[j] += movesFormRight;
            ballsFormRight += boxes[j] - '0';
            movesFormRight += ballsFormRight;
        }

        return ans;
    }
};