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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<pair<TreeNode*,pair<int,int>>> q;
        map<int,map<int,multiset<int>>> nodes;
        q.push({root,{0,0}});
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                auto temp = q.front();
                TreeNode* x = temp.first;
                q.pop();
                int vlevel = temp.second.first, hlevel = temp.second.second; 
                nodes[vlevel][hlevel].insert(x->val);
                if(x->left) q.push({x->left,{vlevel-1,hlevel+1}});
                if(x->right) q.push({x->right, {vlevel+1, hlevel+1}});
            }
        }
        for(auto it1:nodes){
            vector<int> temp;
            auto x = it1.second;
            for(auto it2: x){
                temp.insert(temp.end(),it2.second.begin(), it2.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};