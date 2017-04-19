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
    int getLens(ListNode *head){
        int lens = 0;
        ListNode *cur = head;
        while(cur){
            ++lens;
            cur = cur->next;
        }
        return lens;
    }

    ListNode *reverseLinkList(ListNode *head){
        ListNode *cur = head, *pre = NULL;
        while(cur){
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        int lens = getLens(head);
        int indexs = lens/k;
        ListNode *dummy = new ListNode(0);
        ListNode *tmp = dummy, *cur = head;
        while(indexs--){
            ListNode *tail = cur, *pre = NULL;
            int n = k-1;
            while(tail&&n--){
                tail = tail->next;
            }
            pre = tail->next;
            tail->next = NULL;
            tmp->next = reverseLinkList(cur);
            tmp = cur;
            cur = pre;
        }
        tmp->next = cur;
        return dummy->next;
    }
};