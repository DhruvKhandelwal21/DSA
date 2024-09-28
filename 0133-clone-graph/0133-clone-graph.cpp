/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> mp;
    Node* dfs(Node *node){
        Node *temp = new Node(node->val);
        vector<Node*> neighbour;
        mp[node] = temp;
        for(auto it: node->neighbors){
            if(mp.count(it)){
                neighbour.push_back(mp[it]);
            }else{
                neighbour.push_back(dfs(it));
            }
        }
        temp->neighbors = neighbour;
        return temp;
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        return dfs(node);
    }
};