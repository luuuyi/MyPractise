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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ret;
        if(root == NULL)    return ret;

        stack<TreeNode *> stk;
        TreeNode *tmp = root;
        while(tmp || (!stk.empty())){
            if(tmp){
                stk.push(tmp);
                tmp = tmp->left;
            }
            else{
                TreeNode *p = stk.top();
                ret.push_back(p->val);
                stk.pop();
                tmp = p->right;
            }
        }
        return ret;
    }
};