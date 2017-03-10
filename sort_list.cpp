/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 //solution 1
class Solution {
public:
    vector<int> conts_;

    ListNode *sortList(ListNode *head) {
        if(head == NULL)    return NULL;

        ListNode *t_head = head;
        while(t_head){
            conts_.push_back(t_head->val);
            t_head = t_head->next;
        }
        int lens = conts_.size();
        vector<int> tmp(lens,0);
        mergeSort(conts_,0,lens-1,tmp);
        ListNode *result = head;
        int i = 0;
        while(result){
            result->val = conts_[i];
            result = result->next;
            ++i;
        }
        return head;
    }

    void mergeList(vector<int>& n, int l, int m, int r, vector<int>& tmp){
        int i = l, j = m + 1, k = l;
        while (i <= m && j <= r)  
        {  
            if (n[i] <= n[j])  
                tmp[k++] = n[i++];  
            else  
                tmp[k++] = n[j++];  
        }  
        
        while (i <= m)  
            tmp[k++] = n[i++];  
        
        while (j <= r)  
            tmp[k++] = n[j++]; 

        for (i = 0; i < r-l+1; i++)
            n[l + i] = tmp[l+i];
    }

    void mergeSort(vector<int>& n, int l, int r, vector<int>& tmp){
        if(l<r){
            int mid = (l + r) / 2;
            mergeSort(n, l, mid, tmp);
            mergeSort(n, mid+1, r, tmp);
            mergeList(n, l, mid, r, tmp);
        }
    }
};

//solution 2
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next) return head;
         
        ListNode* p = head, *q = head->next;
        while(q && q->next) {
            p = p->next;
            q = q->next->next;
        }
         
        ListNode* left = sortList(p->next);
        p->next = NULL;
        ListNode* right = sortList(head);
         
        return merge(left, right);
    }
     
     
    ListNode *merge(ListNode *left, ListNode *right) {
        ListNode dummy(0);
        ListNode *p = &dummy;
        while(left && right) {
            if(left->val < right->val) {
                p->next = left;
                left = left->next;
            }
            else {
                p->next = right;
                right = right->next;
            }
            p = p->next;
        }
        if (left) p->next = left;
        if (right) p->next = right;
        return dummy.next;
    }
};
