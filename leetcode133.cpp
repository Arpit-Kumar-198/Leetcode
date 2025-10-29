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
    vector<Node*> check;
    void dfs(Node* node, Node* clone){
        for(auto it : node->neighbors){
            if(check[it->val]){
                clone->neighbors.push_back(check[it->val]);
            }
            else{
                Node* t = new Node(it->val);
                check[t->val] = t;
                clone->neighbors.push_back(t);
                dfs(it,t);
            }
            
        }
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        Node* clone = new Node(node->val);
        check.resize(101,NULL);
        check[clone->val] = clone;
        dfs(node,clone);
        return clone;
    }
};