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
    ListNode *deleteDuplicates(ListNode *head) {
        if(head==NULL||head->next==NULL)    return head;
        ListNode *dummy = new ListNode(0x7fffffff);
        dummy->next = head;
        ListNode *pre=dummy, *cur=head;
        while(cur){
            if(cur->val==pre->val){
                cur = cur->next;
            }
            else{
                ListNode *tmp = cur;
                cur = cur->next;
                pre->next = tmp;
                pre = tmp;
            }
        }
        pre->next = NULL;
        return dummy->next;
    }
};