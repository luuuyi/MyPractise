/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if(head==NULL)  return NULL;
        ListNode *middle = findMiddle_v2(head);
        TreeNode *p_node = new TreeNode(middle->val);
        ListNode *right = middle->next;
        p_node->right = sortedListToBST(right);
        ListNode *p = head;
        if(p!=middle){
            while(p->next!=middle)  p = p->next;
            p->next = NULL;
            p_node->left = sortedListToBST(head);
        }
        return p_node;
    }

    ListNode *findMiddle_v2(ListNode * head){
        if (head == NULL || head->next == NULL){
            return head;
        }

        ListNode *p = head, *q = head;
        while (q && q->next){
            p = p->next;
            q = q->next->next;
        }
        return p;
    }
};