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
    int maxLen = 0;
public:
    int longestZigZag(TreeNode* root) {
        if(root->left){
            DFS(root->left, 0, true);
        }
        if(root->right){
            DFS(root->right, 0, false);
        }

        return maxLen;
    }

    void DFS(TreeNode* root, int len, bool left){
        if(!root){
            maxLen = max(maxLen, len);
            return;
        } 

        len++;
        if(left){
            DFS(root->right, len, false);
            DFS(root->left, 0, true);
        }
        else{
            DFS(root->left, len, true);
            DFS(root->right, 0, false);
        }
    }
};