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
    void inorder(TreeNode* root, vector<int> &v){
        if(!root) return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        vector<int> v1,v2;
        inorder(root,v1);
        v2.assign(v1.begin(),v1.end());
        sort(v2.begin(), v2.end());
        if(v1==v2){
            for(int i=1;i<v2.size();i++){
                if(v2[i-1]==v2[i]) return false;
            }
            return true;
        }
        return false;
    }
};