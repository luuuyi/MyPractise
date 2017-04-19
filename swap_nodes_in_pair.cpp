/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode *swapNode(ListNode *head1, ListNode *head2){
        head1->next = head2->next;
        head2->next = head1;
        return head2;
    }
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode *dummy = new ListNode(0);
        ListNode *tmp = dummy;
        tmp->next = head;
        for(ListNode *cur = tmp; cur->next&&cur->next->next;cur = cur->next->next){
            cur->next = swapNode(cur->next,cur->next->next);
        }
        return dummy->next;
    }
};