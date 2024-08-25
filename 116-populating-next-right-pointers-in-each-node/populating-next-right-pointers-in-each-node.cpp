/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
   void solve(Node* root){
    if(!root) return;
    if(root->left){
        root->left->next = root->right;
        solve(root->left);
    }
    if(root->right){
        if(root->next){
            Node* temp = root->next;
            root->right->next = temp->left;
        }
        solve(root->right);
    }
    return;
   }
    Node* connect(Node* root) {
        solve(root);
        return root;
    }
};