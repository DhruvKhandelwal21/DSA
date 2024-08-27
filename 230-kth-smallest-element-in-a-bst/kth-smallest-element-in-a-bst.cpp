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
  void solve(TreeNode* root, vector<int> &inorder){
    if(!root) return;
    if(root->left) solve(root->left, inorder);
    inorder.push_back(root->val);
    if(root->right) solve(root->right, inorder);
    return;
  }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorder;
        solve(root, inorder);
        return inorder[k-1];
    }
};