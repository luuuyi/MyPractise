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
    void recoverTree(TreeNode *root) {
        if(root==NULL)  return ;
        bool is_first = true;
        queue<TreeNode *> que;
        vector<TreeNode *> vec;
        findError(root,is_first,vec,que);
        if(vec.size()==2){
            int tmp = vec[0]->val;
            vec[0]->val = vec[1]->val;
            vec[1]->val = tmp;
        }
        if(vec.size()==3){
            int tmp = vec[1]->val;
            vec[1]->val = vec[2]->val;
            vec[2]->val = tmp;
        }
        return;
    }
    void findError(TreeNode *root,bool& is_first,vector<TreeNode *>& vec,queue<TreeNode *>& que){
        if(root==NULL)  return ;
        findError(root->left,is_first,vec,que);
        if(que.size()>=1){
            if(que.back()->val>root->val&&is_first){
                is_first = !is_first;
                vec.push_back(root);
                vec.push_back(que.back());
            }
            else if(que.back()->val>root->val&&!is_first){
                vec.push_back(root);
            }
            que.push(root);
            que.pop();
        }
        else    que.push(root);
        findError(root->right,is_first,vec,que);
    }
};