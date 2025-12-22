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
public:
ListNode* reverse(ListNode* head){
    if(head== NULL || head->next == NULL) return head;
    ListNode* temp = head;
    ListNode* store1 = temp->next;
    ListNode* store2 = NULL;
    while(store1){
        store1 = temp->next;
        temp->next = store2;
        store2 = temp;
        temp = store1;
    }
    return store2;
}
int length(ListNode* head){
    ListNode* temp = head;
    int l = 0;
    while(temp){
        l++;
        temp = temp->next;
    }
    return l;
}
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right || head->next == NULL) return head;
        int len = length(head);
        if(left == 1 && right == len) return reverse(head);

        ListNode* leftlist = head;
        ListNode* middlelist = NULL;
        ListNode* rightlist = NULL;
        ListNode* temp = leftlist;

        int idx = 1;
        if(left == 1){
            while(temp && idx < right){
                idx++;
                temp = temp->next;
            }
            rightlist = temp->next;
            temp->next = NULL;
            leftlist = reverse(leftlist);
            temp = leftlist;
            while(temp->next != NULL) temp = temp->next;
            temp->next = rightlist;
            return leftlist;
        }
        else if(right == len){
            while(temp && idx < left-1){
                idx++;
                temp = temp->next;
            }
            rightlist = temp->next;
            temp->next = NULL;
            rightlist = reverse(rightlist);
            temp->next = rightlist;
            return leftlist;
        }
        
        while(temp && idx < left-1){
            idx++;
            temp = temp->next;
        }
        idx++;
        middlelist = temp->next;
        temp->next = NULL;
        temp = middlelist;
        while(temp && idx < right) {
            idx++;
            temp = temp->next;
        }
        rightlist = temp->next;
        temp->next = NULL;
        middlelist = reverse(middlelist);
        temp = leftlist;
        while(temp->next != NULL) temp = temp->next;
        temp->next = middlelist;
        while(temp->next != NULL) temp = temp->next;
        temp->next = rightlist;
        return leftlist;
        
    }
};