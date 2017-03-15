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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> ret;
        if(root==NULL)  return ret;
        queue<TreeNode *> que1,que2;
        que1.push(root);
        vector<int> tmp;
        while(!que1.empty()||!que2.empty()){
            tmp.clear();
            while(!que1.empty()){
                TreeNode *tmp_tree = que1.front();
                que1.pop();
                tmp.push_back(tmp_tree->val);
                if(tmp_tree->left)  que2.push(tmp_tree->left);
                if(tmp_tree->right)  que2.push(tmp_tree->right);
            }
            if(tmp.size()!=0)   ret.push_back(tmp);
            tmp.clear();
            while(!que2.empty()){
                TreeNode *tmp_tree = que2.front();
                que2.pop();
                tmp.push_back(tmp_tree->val);
                if(tmp_tree->left)  que1.push(tmp_tree->left);
                if(tmp_tree->right)  que1.push(tmp_tree->right);
            }
            if(tmp.size()!=0)   ret.push_back(tmp);
        }
        return ret;
    }
};