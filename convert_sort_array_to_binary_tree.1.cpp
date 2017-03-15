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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        int lens = num.size();
        if(lens==0)  return NULL;
        return sorted_array_to_BST(num,0,lens-1);
    }

    TreeNode *sorted_array_to_BST(vector<int> &num, int start, int stop){
        if(start<=stop){
            int middle = (start+stop+1)/2;
            TreeNode *p_node = new TreeNode(num[middle]);
            int right = middle+1;
            p_node->right = sorted_array_to_BST(num,right,stop);
            int left = middle -1;
            p_node->left = sorted_array_to_BST(num,start,left);
            return p_node;
        }
        return NULL;
    }
};