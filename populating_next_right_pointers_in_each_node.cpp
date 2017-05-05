/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root==NULL)  return;
        root->next = NULL;
        TreeLinkNode *tmp = root;
        while(tmp->left){
            TreeLinkNode *dummy_tmp = new TreeLinkNode(0);
            TreeLinkNode *tmp_cur = tmp, *dummy = dummy_tmp;
            while(tmp_cur&&tmp_cur->left&&tmp_cur->right){
                dummy->next = tmp_cur->left;
                dummy->next->next = tmp_cur->right;
                dummy = dummy->next->next;
                tmp_cur = tmp_cur->next;
            }
            tmp = tmp->left;
            delete dummy_tmp;
        }
    }
};