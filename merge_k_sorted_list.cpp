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
    ListNode *mergeList(ListNode *l1,ListNode *l2){
        ListNode *dummy = new ListNode(0);
        ListNode *tmp = dummy, *t1 = l1, *t2 = l2;
        while(t1&&t2){
            if(t1->val>t2->val){
                tmp->next = t2;
                tmp = tmp->next;
                t2 = t2->next;
            }
            else{
                tmp->next = t1;
                tmp = tmp->next;
                t1 = t1->next;
            }
        }
        if(t1)  tmp->next = t1;
        if(t2)  tmp->next = t2;
        return dummy->next;
    }

    ListNode *mergeK(vector<ListNode *> &lists, int begin, int end){
        if(begin<end){
            int mid = (begin+end)/2;
            ListNode *left = mergeK(lists,begin,mid);
            ListNode *right = mergeK(lists,mid+1,end);
            return mergeList(left,right);
        }
        else    return lists[end];
    }
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int lens = lists.size();
        if(lens==0) return NULL;
        return mergeK(lists,0,lens-1);
    }
};