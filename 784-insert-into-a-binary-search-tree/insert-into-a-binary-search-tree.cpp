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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* x = root;
        if(!root){
            TreeNode* ans = new TreeNode(val);
            return ans;
        }
        while(x){
           if(x->val<val){
             if(x->right){
                x = x->right;
             }else{
                TreeNode *temp = new TreeNode(val);
                x->right = temp;
                break;
             }
           }else {
            if(x->left){
                x = x->left;
            }else {
               TreeNode *temp = new TreeNode(val);
                x->left = temp;
                break; 
            }
           }
        }
        return root;
    }
};