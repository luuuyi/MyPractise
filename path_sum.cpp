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
    bool hasPathSum(TreeNode *root, int sum) {
        if(root==NULL)  return false;
        return dfs(root,0,sum);
    }
    bool dfs(TreeNode *root, int cur, int sum){
        if(root->right==NULL&&root->left==NULL){
            if(cur+root->val==sum)  return true;
            else    return false;
        }
        if(root->left){
            cur += root->val;
            if(dfs(root->left,cur,sum)) return true;
            cur -= root->val;
        }
        if(root->right){
            cur += root->val;
            if(dfs(root->right,cur,sum)) return true;
            cur -= root->val;
        }
        return false;
    }
};