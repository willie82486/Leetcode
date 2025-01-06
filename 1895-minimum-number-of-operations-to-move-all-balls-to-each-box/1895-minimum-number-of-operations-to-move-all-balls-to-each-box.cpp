class Solution {
public:
    vector<int> minOperations(string boxes) {
        int len = boxes.length();
        vector<int> ans(len, 0);

        int ballsToLeft = 0, movesToLeft = 0;
        int ballsToRight = 0, movesToRight = 0;

        // Single pass: calculate moves from both left and right
        for (int i = 0; i < len; i++) {
            // Left pass
            ans[i] += movesToLeft;
            ballsToLeft += boxes[i] - '0';
            movesToLeft += ballsToLeft;

            // Right pass
            int j = len - 1 - i;
            ans[j] += movesToRight;
            ballsToRight += boxes[j] - '0';
            movesToRight += ballsToRight;
        }

        return ans;
    }
};