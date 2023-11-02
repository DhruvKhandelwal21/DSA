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
    int countNode(TreeNode* root){
        if(root==NULL)
            return 0;
        return 1 + countNode(root->left) + countNode(root->right);
    }
    int summ(TreeNode* root,int &ans)
    {
        if(root==NULL)
            return 0;
        int sum=(root->val + summ(root->left,ans) + summ(root->right,ans));
        int n=countNode(root);
        if(sum/n==root->val)
            ans++;
        return sum;
    }
    int averageOfSubtree(TreeNode* root) {
        int sum,ans=0;
        sum=summ(root,ans);
        return ans;
    }
};