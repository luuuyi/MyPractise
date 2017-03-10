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
    void reorderList(ListNode *head) {
        if (head == NULL || head->next == NULL){
            return;
        }

        ListNode *mid = findMiddle(head);
        ListNode *right = reverseList(mid->next);
        mid->next = NULL;
        ListNode *left = head;
        head = mergeList(left,right);
    }

    ListNode *findMiddle(ListNode * head){
        if (head == NULL || head->next == NULL){
            return head;
        }

        ListNode *p = head, *q = head->next;
        while (q && q->next){
            p = p->next;
            q = q->next->next;
        }
        return p;
    }

    ListNode *reverseList(ListNode *head){
        if (head == NULL || head->next == NULL){
            return head;
        }
        ListNode *cur = head;
        ListNode *pre = NULL;
        while (cur){
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

    ListNode *mergeList(ListNode * l1, ListNode * l2){
        if (l1 == NULL)	return l2;
        if (l2 == NULL)	return l1;

        ListNode dummy = ListNode(0);
        ListNode *p = &dummy;
        while (l1 &&l2){
            p->next = l1;
            p = p->next;
            l1 = l1->next;
            p->next = l2;
            p = p->next;
            l2 = l2->next;
        }
        if (l1)	p->next = l1;
        if (l2)	p->next = l2;
            
        return dummy.next;
    }
};