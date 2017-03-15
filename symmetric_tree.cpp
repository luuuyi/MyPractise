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
    bool isSymmetric(TreeNode *root) {
        if(root==NULL)  return true;
        return is_equel(root->left,root->right);
    }
    bool is_equel(TreeNode *root1,TreeNode *root2){
        if(root1==NULL&&root2==NULL)    return true;
        if(root1!=NULL&&root2!=NULL){
            if(root1->val==root2->val){
                return is_equel(root1->left,root2->right)&&is_equel(root1->right,root2->left);
            } 
        }
        return false;
    }
};