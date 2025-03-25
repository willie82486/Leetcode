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
    bool vecSymmetric(vector<int>& vec){
        int left = 0;
        int right = vec.size() - 1;
        while(left <= right){
            if(vec[left] != vec[right]) return false;
            left++;
            right--;
        }
        return true;

    }
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> qu;
        if(root == nullptr) return true;
        qu.push(root);
        while(!qu.empty()){
            int size = qu.size();
            vector<int> vec;
            for(int i = 0; i < size; i++){
                TreeNode* curNode = qu.front();
                qu.pop();
                if(curNode->left == nullptr) vec.push_back(-101);
                else{
                    vec.push_back(curNode->left->val);
                    qu.push(curNode->left);
                }
                if(curNode->right == nullptr) vec.push_back(-101);
                else{
                    vec.push_back(curNode->right->val); 
                    qu.push(curNode->right);
                }
            }
            if(!vecSymmetric(vec)) return false;
        }
        return true;
    }
};