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
    vector<int> ans;
    int currNum = 0,currFreq = 0,maxFreq = 0;
    void dfs(TreeNode *root){
        if(root==NULL){
            return;
        }
        dfs(root->left);
        if(root->val==currNum){
            currFreq++;
        }else{
            currNum = root->val;
            currFreq = 1;
        }
        if(currFreq>maxFreq){
            maxFreq = currFreq;
            ans = {};
            ans.push_back(currNum);
        }else if(currFreq==maxFreq){
            ans.push_back(root->val);
            
        }
        dfs(root->right);
    }
    
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return ans;
    }
};