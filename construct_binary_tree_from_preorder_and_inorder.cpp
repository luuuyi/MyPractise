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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int pre_lens = preorder.size();
        int in_lens = inorder.size();
        if(pre_lens==0&&in_lens==0)   return NULL;
        return BST(preorder,0,pre_lens-1,inorder,0,in_lens-1);
    }
    TreeNode *BST(vector<int> &preorder,int pre_s, int pre_e, vector<int> &inorder,int in_s, int in_e){
        if(pre_s<=pre_e&&in_s<=in_e){
            int root_pre_i = pre_s, root_pre_v = preorder[pre_s];
            int root_in_i = in_s;
            for(int i=in_s;i<=in_e;++i){
                if(inorder[i]==root_pre_v)  root_in_i = i;
            }
            TreeNode *p_node = new TreeNode(root_pre_v);
            int left_lens = root_in_i-in_s;
            int right_lens = in_e - root_in_i;
            p_node->left = BST(preorder,pre_s+1,pre_s+left_lens,inorder,in_s,root_in_i-1);
            p_node->right = BST(preorder,pre_s+left_lens+1,pre_e,inorder,root_in_i+1,in_e);
            return p_node;
        }
        return NULL;
    }
};