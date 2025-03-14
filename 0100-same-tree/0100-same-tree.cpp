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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr) return true;
        if(!(p != nullptr && q != nullptr)) return false; 
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(p);
        q2.push(q);
        if(q1.front() -> val != q2.front() -> val) return false;
        while(!q1.empty() && !q2.empty()){
            int size = q1.size();
            for(int i = 0; i < size; i++){
                TreeNode* q1_tmp = q1.front();
                TreeNode* q2_tmp = q2.front();
                q1.pop();
                q2.pop();
                if(q1_tmp -> left != nullptr && q2_tmp -> left != nullptr){
                    if(q1_tmp -> left -> val != q2_tmp -> left -> val) return false;
                    q1.push(q1_tmp -> left);
                    q2.push(q2_tmp -> left);
                }
                else{
                    if(q1_tmp -> left != nullptr || q2_tmp -> left != nullptr) return false;
                }
                if(q1_tmp -> right != nullptr && q2_tmp -> right != nullptr){
                    if(q1_tmp -> right -> val != q2_tmp -> right -> val) return false;
                    q1.push(q1_tmp -> right);
                    q2.push(q2_tmp -> right);
                }
                else{
                    if(q1_tmp -> right != nullptr || q2_tmp -> right != nullptr) return false;
                }
            }
        }

        return true;
    }
};