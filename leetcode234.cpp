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
    ListNode* temp = head;
    ListNode* store = NULL;
    ListNode* p = NULL;
    while(temp){
        if(p == NULL) {
            p = temp;
            temp = temp->next;
            p->next = NULL;
        }
        else{
            store = temp->next;
            temp->next = p;
            p = temp;
            temp = store;
        }
    }
    return p;
}
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;
        int len = 0;
        ListNode* temp = head;
        while(temp){
            len++;
            temp = temp->next;
        }
        len = len/2;
        int cnt = 0;
        temp = head;
        while(temp && cnt < len-1) {
            temp = temp->next;
            cnt++;
        }
        ListNode* remain = temp->next;
        temp->next = NULL;
        remain = reverse(remain);
        temp = head;
        while(temp){
            if(remain && temp->val != remain->val) return false;
            else{
                if(remain) remain = remain->next;
                temp = temp->next;
            }
        }
        return true;
    }
};