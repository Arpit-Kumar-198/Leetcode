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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL) return head;
        if(head->next == NULL) return head;
        vector<ListNode*> v;
        ListNode* t = head;
        while(t){
            v.push_back(t);
            t = t->next;
        }
        int n = v.size();
        for(int i = 0; i < n-1; i++){
            int j = i+1;
            while(j > 0 && v[j]->val < v[j-1]->val){
                swap(v[j],v[j-1]);
                j--;
            }
        }

        ListNode* res = new ListNode(-1);
        ListNode* t2 = res;
        for(int i = 0; i < n; i++){
            t2->next = v[i];
            t2 = t2->next;
        }
        t2->next = NULL;
        return res->next;
    }
};