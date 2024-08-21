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
TreeNode* build(vector<int> & pre, int pst, int pnd, vector<int> &in, int ist, int ind, unordered_map<int,int> &mp ){
    if(pst>pnd || ist>ind){
        return NULL;
    }
    TreeNode* rootNode = new TreeNode(pre[pst]);
    int rootVal = mp[pre[pst]];
    int limit = rootVal - ist;
    rootNode->left = build(pre, pst+1, pst+limit, in, ist, rootVal-1, mp);
    rootNode->right = build(pre, pst+limit+1, pnd, in, rootVal+1, ind, mp);
    return rootNode;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
       for(int i=0;i<inorder.size();i++){
        mp[inorder[i]] = i;
       }
    
        TreeNode* ans = build(preorder,0, preorder.size()-1, inorder, 0, inorder.size()-1, mp );
        return ans;
    }
};