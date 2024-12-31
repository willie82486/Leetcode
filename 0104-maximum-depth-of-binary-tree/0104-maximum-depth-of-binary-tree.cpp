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
public:
    void DFS(TreeNode* node, int curLevel, int& maxLevel){
        if(node == NULL){
            maxLevel = max(maxLevel, curLevel - 1);
            return;
        }

        DFS(node->left, curLevel + 1, maxLevel);
        DFS(node->right, curLevel + 1, maxLevel);
        return;
    }

    int maxDepth(TreeNode* root) {
        int maxLevel = 0;
        if(root == NULL)
            return 0;
        DFS(root, 1, maxLevel);
        
        return maxLevel;
    }
};