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
    bool hasCycle(ListNode *head) {
        if(head==NULL||head->next == NULL){
            return NULL;
        }

        int n = steps2Meet(head);
        if(n==-1)   return false;
        else return true;
    }
    int steps2Meet(ListNode *head){
        ListNode *slow = head;
        ListNode *fast = head->next;
        int n = 1;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            ++n;
            if(slow == fast)    return n;
        }
        return -1;
    }
};

