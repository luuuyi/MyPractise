/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //solution 1
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ret;
        if(root == NULL)    return ret;

        stack<TreeNode *> stk;
        TreeNode *tmp = root;
        stk.push(root);
        ret.push_back(root->val);
        while(!stk.empty()){
            if(tmp->left){
                stk.push(tmp->left);
                ret.push_back(tmp->left->val);
                tmp = tmp->left;
                continue;
            }
            TreeNode *node = stk.top();
            stk.pop();
            if(node->right){
                tmp = node->right;
                stk.push(tmp);
                ret.push_back(tmp->val);
            }
        }
        return ret;
    }
};

//solution 2
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ret;
        if(root == NULL)    return ret;

        stack<TreeNode *> stk;
        TreeNode *tmp = root;
        while(tmp || (!stk.empty())){
            if(tmp){
                ret.push_back(tmp->val);
                stk.push(tmp);
                tmp = tmp->left;
            }
            else{
                TreeNode *p = stk.top();
                stk.pop();
                tmp = p->right;
            }
        }
        return ret;
    }
};