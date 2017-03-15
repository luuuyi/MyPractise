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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> ret;
        if(root==NULL)  return ret;
        bool is_left_to_right = true;
        stack<TreeNode *> stk1,stk2;
        stk1.push(root);
        vector<int> tmp;
        while(!stk1.empty()||!stk2.empty()){
            tmp.clear();
            while(!stk1.empty()){
                TreeNode *tmp_tree = stk1.top();
                stk1.pop();
                tmp.push_back(tmp_tree->val);
                if(is_left_to_right){
                    if(tmp_tree->left){
                        stk2.push(tmp_tree->left);
                    }
                    if(tmp_tree->right){
                        stk2.push(tmp_tree->right);
                    }
                }
                else{
                    if(tmp_tree->right){
                        stk2.push(tmp_tree->right);
                    }
                    if(tmp_tree->left){
                        stk2.push(tmp_tree->left);
                    }
                }
            }
            if(tmp.size()!=0)   ret.push_back(tmp);
            is_left_to_right = !is_left_to_right;
            tmp.clear();
            while(!stk2.empty()){
                TreeNode *tmp_tree = stk2.top();
                stk2.pop();
                tmp.push_back(tmp_tree->val);
                if(is_left_to_right){
                    if(tmp_tree->left){
                        stk1.push(tmp_tree->left);
                    }
                    if(tmp_tree->right){
                        stk1.push(tmp_tree->right);
                    }
                }
                else{
                    if(tmp_tree->right){
                        stk1.push(tmp_tree->right);
                    }
                    if(tmp_tree->left){
                        stk1.push(tmp_tree->left);
                    }
                }
            }
            if(tmp.size()!=0)   ret.push_back(tmp);
            is_left_to_right = !is_left_to_right;
        }
        return ret;
    }
};