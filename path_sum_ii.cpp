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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int>> ret;
        if(root==NULL)  return ret;
        vector<int> tmp;
        dfs(root,0,sum,ret,tmp);
        return ret;
    }
    void dfs(TreeNode *root, int cur, int sum, vector<vector<int>>& ret, vector<int>& tmp){
        if(root->right==NULL&&root->left==NULL){
            if(cur+root->val==sum){
                tmp.push_back(root->val);
                ret.push_back(tmp);
                tmp.pop_back();
            }
            return ;
        }
        if(root->left){
            cur += root->val;
            tmp.push_back(root->val);
            dfs(root->left,cur,sum,ret,tmp);
            tmp.pop_back();
            cur -= root->val;
        }
        if(root->right){
            cur += root->val;
            tmp.push_back(root->val);
            dfs(root->right,cur,sum,ret,tmp);
            tmp.pop_back();
            cur -= root->val;
        }
        return;
    }
};