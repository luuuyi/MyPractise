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
        ListNode *pre=dummy, *cur=head,*next = head->next;
        while(next){
            if(cur->val==next->val){
                while(next&&next->val==cur->val){
                    next = next->next;
                }
                if(next){
                    ListNode *tmp= next;
                    next = next->next;
                    cur = tmp;
                    pre->next = tmp;
                }
                else{
                    pre->next = NULL;
                }
            }
            else{
                next = next->next;
                cur = cur->next;
                pre = pre->next;
            }
        }
        return dummy->next;
    }
};