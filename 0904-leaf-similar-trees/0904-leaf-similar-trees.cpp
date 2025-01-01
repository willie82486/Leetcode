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
    void DFS(TreeNode* node, vector<int>& leafVal){
        if(node->left == NULL && node->right == NULL){
            leafVal.push_back(node->val);
            return;
        }

        if(node->left != NULL) DFS(node->left, leafVal);
        if(node->right != NULL) DFS(node->right, leafVal);
        return;
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafVal1;
        vector<int> leafVal2;

        DFS(root1, leafVal1);
        DFS(root2, leafVal2);

        if(leafVal1 == leafVal2) return true;
        return false;
    }
};