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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ret;
        if(root == NULL)    return ret;

        stack<pair<TreeNode *,bool>> stk;
        TreeNode *tmp = root;
        pair<TreeNode *,bool> temp;
        while(tmp || (!stk.empty())){
            while(tmp){
                stk.push(make_pair(tmp,true));
                tmp = tmp->left;
            }
            if(!stk.empty()){
                temp = stk.top();
                stk.pop();
                if(temp.second){
                    temp.second = false;
                    tmp = temp.first->right;
                    stk.push(temp);
                }
                else{
                    ret.push_back(temp.first->val);
                    tmp = NULL;
                }
            }
        }
        return ret;
    }
};

//solution 2
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ret;
        if(root == NULL)    return ret;

        stack<TreeNode *> stk;
        TreeNode *cur = root, *pre = NULL;
        stk.push(cur);
        while(!stk.empty()){
            cur = stk.top();
            if((cur->left == NULL&&cur->right == NULL)||(pre!=NULL
            &&(pre==cur->left||pre==cur->right))){
                ret.push_back(cur->val);
                stk.pop();
                pre = cur;
            }
            else{
                if(cur->right) stk.push(cur->right);
                if(cur->left)   stk.push(cur->left);
            }
        }
        return ret;
    }
};