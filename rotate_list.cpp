/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
/*private:
    ListNode *reverse(ListNode *head){
        ListNode *pre = NULL, *cur = head;
        while(cur){
            ListNode *nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }*/
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if(head==NULL||k==0)  return head;
        int lens = 0;
        ListNode *p=head,*tail = NULL;
        while(p){
            ++lens;
            tail = p;
            p = p->next;
        }
        if(k>lens){
            //ListNode *tmp = reverse(head);
            return rotateRight(head,k-lens);
        }
        else if(k==lens)    return head;
        int n = lens - k;
        ListNode *cur=head,*pre = NULL;
        while(n--){
            pre = cur;
            cur = cur->next;
        }
        pre->next = NULL;
        tail->next = head;
        return cur;
    }
};