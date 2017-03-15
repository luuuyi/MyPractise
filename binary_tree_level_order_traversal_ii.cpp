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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int>> ret;
        if(root==NULL)  return ret;
        queue<TreeNode *> que1;
        queue<TreeNode *> que2;
        vector<int> tmp;
        que1.push(root);
        tmp.push_back(root->val);
        ret.push_back(tmp);
        while((!que1.empty())||(!que2.empty())){
            tmp.clear();
            while(!que1.empty()){
                TreeNode *tmp_tree = que1.front();
                que1.pop();
                if(tmp_tree->left!=NULL){
                    que2.push(tmp_tree->left);
                    tmp.push_back(tmp_tree->left->val);
                }
                if(tmp_tree->right!=NULL){
                    que2.push(tmp_tree->right);
                    tmp.push_back(tmp_tree->right->val);
                }
            }
            if(tmp.size()!=0)   ret.push_back(tmp);
            tmp.clear();
            while(!que2.empty()){
                TreeNode *tmp_tree = que2.front();
                que2.pop();
                if(tmp_tree->left!=NULL){
                    que1.push(tmp_tree->left);
                    tmp.push_back(tmp_tree->left->val);
                }
                if(tmp_tree->right!=NULL){
                    que1.push(tmp_tree->right);
                    tmp.push_back(tmp_tree->right->val);
                }
            }
            if(tmp.size()!=0)   ret.push_back(tmp);
        }
        vector<vector<int>> res(ret.rbegin(),ret.rend());
        return res;
    }
};