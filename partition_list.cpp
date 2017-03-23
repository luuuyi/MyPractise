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
    ListNode *partition(ListNode *head, int x) {
        if(head==NULL)  return NULL;
        queue<ListNode *> que1,que2;
        ListNode * p = head;
        while(p){
            if(p->val<x)    que1.push(p);
            else    que2.push(p);
            p = p->next;
        }
        ListNode *dummy = new ListNode(0);
        ListNode *q = dummy;
        while(!que1.empty()){
            q->next = new ListNode(que1.front()->val);
            q = q->next;
            que1.pop();
        }
        while(!que2.empty()){
            q->next = new ListNode(que2.front()->val);
            q = q->next;
            que2.pop();
        }
        return dummy->next;
    }
};
