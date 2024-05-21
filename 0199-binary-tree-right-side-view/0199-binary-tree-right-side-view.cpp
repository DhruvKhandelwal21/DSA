/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    map<int,int> mp;
    void solve(TreeNode* root, int lvl){
        if(!root) return;
        if(mp.find(lvl)==mp.end()){
            mp[lvl] = root->val;
        }
        solve(root->right, lvl+1);
        solve(root->left, lvl+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        solve(root,0);
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
        // iterative solution
       
    //     queue<TreeNode*> q;
    //     vector<int> ans;
    //     if(!root) return ans;
    //    q.push(root);
    //    while(!q.empty()){
    //     int n = q.size();
    //     for(int i=0;i<n;i++){
    //         TreeNode* temp = q.front();
    //         q.pop();
    //         if(i==n-1) ans.push_back(temp->val);
    //         if(temp->left) q.push(temp->left);
    //         if(temp->right) q.push(temp->right);
    //     }
    //    }
       return ans;
    }
};