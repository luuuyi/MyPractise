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
        TreeLinkNode *tmp = root;
        while(tmp){
            TreeLinkNode *nxt = NULL;
            while(tmp){
                if(tmp->left){
                    nxt = tmp->left;
                    break;
                }
                if(tmp->right){
                    nxt = tmp->right;
                    break;
                }
                tmp = tmp->next;
            }
            TreeLinkNode *dummy = new TreeLinkNode(0);
            TreeLinkNode *dummy_tmp = dummy;
            while(tmp){
                if(tmp->left){
                    dummy_tmp->next = tmp->left;
                    dummy_tmp = dummy_tmp->next;
                }
                if(tmp->right){
                    dummy_tmp->next = tmp->right;
                    dummy_tmp = dummy_tmp->next;
                }
                tmp = tmp->next;
            }
            tmp = nxt;
        }
    }
};