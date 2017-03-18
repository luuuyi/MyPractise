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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(head==NULL)  return head;
        if(n-m+1==1)    return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *p = head, *pre = dummy, *end=head;
        int tmp_m =m,tmp_n = n;
        while(--tmp_m){
            pre = p;
            p = p->next;
        }
        while(tmp_n--)  end = end->next;
        int diff = n-m+1;
        while(diff--){
            ListNode *tmp = p->next;
            p->next = end;
            end =p;
            p = tmp;
        }
        pre->next = end;
        return dummy->next;
    }
};