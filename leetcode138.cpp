/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        Node* copy = new Node(-1);
        Node* t = copy;
        Node* temp = head;
        unordered_map<Node*, Node*> st;

        while(temp != NULL){
            if(st.find(temp) != st.end()) {
                t->next = st[temp];
                t = t->next;
            }
            else {
                t->next = new Node(temp->val);
                t = t->next;
                st[temp] = t;
            }
            
            Node* p = temp->random;
            if(p == NULL) t->random = NULL;
            else{
                if(st.find(p) != st.end()){
                    t->random = st[p];
                }
                else{
                    t->random = new Node(p->val);
                    st[p] = t->random;
                }
            }
            temp = temp->next;
        }
        return copy->next;
    }
};