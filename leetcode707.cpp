class Node{
public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
    Node(){
        this->val = 0;
        this->next = NULL;
    }
};

class MyLinkedList {
public:
    Node* head;
    Node* tail;
    int size;
    MyLinkedList() {
        head = tail = NULL;
        size = 0;
    }
    
    int get(int index) {
        if(index < 0 || index >= size) return -1;
        else if(index == 0) return head->val;
        else if(index == size-1) return tail->val;
        else{
            int p = 0;
            Node* t = head;
            while(t && p < index){
                t = t->next;
                p++;
            }
            return t->val;
        }
    }
    
    void addAtHead(int val) {
        Node* temp = new Node(val);
        if(head == NULL){
            head = temp;
            tail = temp;
            size++;
            return;
        }
        temp->next = head;
        head = temp;
        size++;
        return;
    }
    
    void addAtTail(int val) {
        Node* temp = new Node(val);
        if(tail == NULL){
            head = temp;
            tail = temp;
            size++;
            return;
        }
        tail->next = temp;
        tail = temp;
        size++;
        return;
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0 || index > size) return;
        if(index == 0) {
            addAtHead(val);
            return;
        }
        else if(index == size) {
            addAtTail(val);
            return;
        }
        else{
            int p = 0;
            Node* temp = new Node(val);
            Node* t = head;
            while(t && p < index-1){
                t = t->next;
                p++;
            }
            temp->next = t->next;
            t->next = temp;
            size++;
            return;
        }
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size) return;
        if(index == 0) {
            if(head == tail){
                Node* t = head;
                delete t;
                head = tail = NULL;
                size--;
                return;
            }
            else{
                Node* t = head;
                head = t->next;
                delete t;
                size--;
                return;
            }
        }
        else if(index == size-1) {
            Node* t = head;
            while(t->next != tail) t = t->next;
            Node* del = t->next;
            tail = t;
            tail->next = NULL;
            delete del;
            size--;
            return;
        }
        else{
            int p = 0;
            Node* t = head;
            while(t && p < index-1){
                t = t->next;
                p++;
            }
            Node* del = t->next;
            t->next = del->next;
            delete del;
            size--;
            return;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */