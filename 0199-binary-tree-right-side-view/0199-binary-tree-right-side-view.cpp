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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> curLevel;

        vector<int> res;
        if(root == NULL)
            return res;
        curLevel.push(root);
        
        while(!curLevel.empty()){
            int size = curLevel.size();
            int value;

            for(int i = 0; i < size; i++){
                TreeNode* nodeInQueue = curLevel.front();
                value = nodeInQueue->val;
                curLevel.pop();
                if(nodeInQueue->left != NULL)
                    curLevel.push(nodeInQueue->left);
                if(nodeInQueue->right != NULL)
                curLevel.push(nodeInQueue->right);
            }
            res.push_back(value);
        }
        return res;
    }
};