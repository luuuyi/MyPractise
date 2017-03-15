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
    bool isValidBST(TreeNode *root) {
        if(root==NULL)  return true;
        bool res = true;
        queue<TreeNode *> que;
        isValid(root,res,que);
        return res;
    }
    void isValid(TreeNode *root,bool& res,queue<TreeNode *>& que){
        if(root==NULL)  return;
        isValid(root->left,res,que);
        if(!que.empty()){
            if(que.back()->val>=root->val)   res = false;
            que.pop();que.push(root);
        }
        else    que.push(root);
        isValid(root->right,res,que);
    }
};