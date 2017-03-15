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
    int maxDepth(TreeNode *root) {
        if(root==NULL)  return 0;
        int maxmium = 0x80000000;
        dfs(root,maxmium,0);
        return maxmium;
    }

    void dfs(TreeNode *root, int& maxmium, int cur){
        if(root->left==NULL&&root->right==NULL){
            cur += 1;
            if(cur>maxmium) maxmium = cur;
            return ;
        }
        if(root->left){
            dfs(root->left,maxmium,cur+1);
        }
        if(root->right){
            dfs(root->right,maxmium,cur+1);
        }
        return ;
    }
};