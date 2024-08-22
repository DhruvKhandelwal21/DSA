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
// int countLeft(TreeNode* root){
//     int cnt = 0;
//     while(root){
//       cnt++;
//       root = root->left;
//     }
//     return cnt;
//   }
//   int countRight(TreeNode* root){
//     int cnt = 0;
//     while(root){
//       cnt++;
//       root = root->right;
//     }
//     return cnt;
//   }

int checkHeight(TreeNode* root, bool &full){
    int cntl = 0,cntr = 0;
    TreeNode* temp = root;
    while(temp){
      cntl++;
      temp = temp->left;
    }
    temp = root;
    while(temp){
      cntr++;
      temp = temp->right;
    }
    // full = cntl==cntr;
    // cout<<cntl<< " "<<cntr<<endl;
    if(cntr!=cntl){
        full  = false;
    }
    cout<<full<<endl;

    return cntl;
  }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        bool full = true;
        int h = checkHeight(root,full);
        if(full) return pow(2,h) - 1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};