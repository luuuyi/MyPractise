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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int post_lens = postorder.size();
        int in_lens = inorder.size();
        if(post_lens==0&&in_lens==0)   return NULL;
        return BST(inorder,0,in_lens-1,postorder,0,post_lens-1);
    }
    TreeNode *BST(vector<int> &inorder,int in_s, int in_e, vector<int> &postorder,int post_s, int post_e){
        if(post_s<=post_e&&in_s<=in_e){
            int root_post_i = post_e, root_post_v = postorder[post_e];
            int root_in_i = in_s;
            for(int i=in_s;i<=in_e;++i){
                if(inorder[i]==root_post_v)  root_in_i = i;
            }
            TreeNode *p_node = new TreeNode(root_post_v);
            int left_lens = root_in_i-in_s;
            int right_lens = in_e - root_in_i;
            p_node->left = BST(inorder,in_s,root_in_i-1,postorder,post_s,post_e-right_lens-1);
            p_node->right = BST(inorder,root_in_i+1,in_e,postorder,post_e-right_lens,post_e-1);
            return p_node;
        }
        return NULL;
    }
};