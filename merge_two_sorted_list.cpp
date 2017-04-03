/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == NULL)  return l2;
        if(l2 == NULL)  return l1;
        ListNode *dummy = new ListNode(0);
        ListNode *d = dummy, *p = l1, *q = l2;
        while(p&&q){
            if(p->val<q->val){
                d->next = p;
                d = p;
                p = p->next;
            }
            else{
                d->next = q;
                d = q;
                q = q->next;
            }
        }
        if(p)    d->next = p;
        if(q)    d->next = q;
        return dummy->next;
    }
};