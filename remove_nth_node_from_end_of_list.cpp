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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(head==NULL||n==0)  return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head; head = dummy;
        ListNode *fast = head, *slow = head;
        int n_tmp = n;
        while(n_tmp--)  fast = fast->next;
        while(fast&&fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
};