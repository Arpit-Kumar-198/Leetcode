/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* temp = head;
        head = head->next;
        temp->next = NULL;
        while(head!=NULL){
            ListNode* t = head;
            head = head->next;
            t->next = temp;
            temp = t;
            
        }
        return temp;

    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        ListNode* temp = head;
        int n = 1;

        ListNode* a = NULL;
        ListNode* b = NULL;
        ListNode* c = NULL;
        ListNode* d = NULL;
        while(temp!=NULL){
            if(n==left-1){
                a = temp;
            }
            if(n==left){
                b = temp;
            }
            if(n==right){
                c = temp;
            }
            if(n==right+1){
                d = temp;
            }
            n++;
            temp = temp->next;
        }

       
        if(a) a->next = NULL;
        c->next = NULL;
        c = reverseList(b);
        if(a) a->next = c;
        b->next = d;
        if(a) return head;
        return c;
    }
};