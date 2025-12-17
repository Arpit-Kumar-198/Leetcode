/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* res = new Node(-1);
        Node* p = res;
        stack<Node*> st;
        Node* temp = head;
        while(temp){
            if(temp->child != NULL){
                Node* t = temp->next;
                st.push(t);
                p->next = temp;
                p = p->next;
                temp = temp->child;
            }
            else {
                p->next = temp;
                p = p->next;
                temp = temp->next;
            }
        }
        while(!st.empty()){
            p->next = st.top();
            st.pop();
            while(p->next != NULL) p = p->next;
        }
        p = res->next;
        if(p) p->prev = NULL;
        temp = res->next;
        if(temp) temp->child = NULL;
        Node* temp2 = NULL;
        if(temp) temp2 = temp->next;
        if(temp2) temp2->child = NULL;
        while(temp2){
            temp2->prev = temp;
            temp = temp->next;
            temp2 = temp2->next;
            if(temp) temp->child = NULL;
            if(temp2) temp2->child = NULL;
        }
        return res->next;
    }
};