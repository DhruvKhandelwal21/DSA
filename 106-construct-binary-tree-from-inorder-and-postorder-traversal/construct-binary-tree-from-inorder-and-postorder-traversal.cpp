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
    TreeNode *build(vector<int> &pos, int pst, int pnd, vector<int> &in, int ins, int ind, unordered_map<int,int> &mp){
        if(pst>pnd || ins>ind){
            return NULL;
        }
        TreeNode *node = new TreeNode(pos[pnd]);
        int k = mp[pos[pnd]];
        int left = ind-k;
        node->left = build(pos,pst, pnd-left-1,in,ins,k-1,mp);
        node->right = build(pos,pnd-left,pnd-1,in,k+1,ind,mp);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        TreeNode* ans = build(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, mp);
        return ans;
    }
};