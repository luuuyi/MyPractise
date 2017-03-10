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
    ListNode *insertionSortList(ListNode *head) {
        if(head==NULL||head->next == NULL)  return head;

        ListNode *cur = head;
        ListNode dummy = ListNode(0x80000000);
        dummy.next = NULL;
        while(cur){
            ListNode *next = cur->next;
            ListNode *tmp = &dummy;
            while(tmp->next&&tmp->next->val < cur->val){
                tmp = tmp->next;
            }
            cur->next = tmp->next;
            tmp->next = cur;
            cur = next;
        }
        return dummy.next;
    }
};