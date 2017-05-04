/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

//solution1
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head==NULL)  return head;
        RandomListNode *dummy = new RandomListNode(0);
        RandomListNode *cur = head, *tmp = dummy;
        unordered_map<RandomListNode *,RandomListNode *> mp;
        while(cur){
            RandomListNode *tmp_node = new RandomListNode(cur->label);
            tmp->next = tmp_node;
            mp[cur] = tmp_node;
            tmp = tmp->next;
            cur = cur->next;
        }
        cur = head;
        while(cur){
            if(cur->random){
                mp[cur]->random = mp[cur->random];
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};

//solution2
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head==NULL)  return head;
        RandomListNode *dummy = new RandomListNode(0);
        RandomListNode *cur = head, *tmp = dummy;
        while(cur){
            RandomListNode *nxt = cur->next;
            RandomListNode *tmp_node = new RandomListNode(cur->label);
            cur->next = tmp_node;
            tmp_node->next = nxt;
            cur = nxt;
        }
        cur = head;
        while(cur){
            if(cur->random){
                cur->next->random = cur->random->next;
            }
            RandomListNode *nxt = cur->next->next;
            tmp->next = cur->next;
            tmp = tmp->next;
            cur = nxt;
        }
        return dummy->next;
    }
};