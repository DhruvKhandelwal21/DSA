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
    int solve(TreeNode* root,int &mx){
        if(!root) return 0;
        int lsum = max(0,solve(root->left,mx));
        int  rsum = max(0,solve(root->right,mx));
        mx = max(mx,lsum + rsum + root->val);
        return root->val + max(lsum,rsum);
    }
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int mx = INT_MIN;
        int temp = solve(root,mx);
        return mx;
    }
};