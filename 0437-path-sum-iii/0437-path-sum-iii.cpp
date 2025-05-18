/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

private:
    int count = 0;
    unordered_map<long, int> umap;

public:
    int pathSum(TreeNode* root, int targetSum) {
        DFS(root, 0, targetSum);
        return count;
    }

    void DFS(TreeNode* root, long long curSum, const int& targetSum){
        if(!root) return;

        curSum += root->val;

        if(curSum == targetSum) count++;
        count += umap[curSum-targetSum];

        umap[curSum]++;
        DFS(root->left, curSum, targetSum);
        DFS(root->right, curSum, targetSum);
        umap[curSum]--;
    }
};