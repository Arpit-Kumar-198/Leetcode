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
int len(ListNode* head){
    int l = 0;
    ListNode* temp = head;
    while(temp){
        temp = temp->next;
        l++;
    }
    return l;
}
ListNode* reverse(ListNode* head){
    ListNode* prev = nullptr;
    ListNode* curr = head;

    while (curr != nullptr) {
        ListNode* nextNode = curr->next; 
        curr->next = prev;               
        prev = curr;                     
        curr = nextNode;                 
    }
    return prev; 
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k == 1) return head;
        
        int l = len(head);
        if(k == l) return head = reverse(head);

        vector<ListNode*> arr(ceil(l/float(k)));

        int i = 1, idx = 0;
        ListNode* temp = head;
        ListNode* store = NULL;
        while(temp){
            while(temp && i < k){
                temp = temp->next;
                i++;
            }
            if(temp) store = temp->next;
            else store = NULL;
            if(temp) temp->next = NULL;
            arr[idx] = head;
            idx++;
            if(store){
                head = store;
                temp = store;
                store = NULL;
            }
            else break;
            i = 1;
        }
        for(int i = 0; i < arr.size(); i++){
            if(i == arr.size()-1 && len(arr[i]) < k) continue;
            else arr[i] = reverse(arr[i]);
        }
        ListNode* ans = new ListNode(-1);

        temp = ans;
        for(int i = 0; i < arr.size(); i++){
            temp->next = arr[i];
            while(temp->next != NULL) temp = temp->next;
        }
        return ans->next;
    }
};