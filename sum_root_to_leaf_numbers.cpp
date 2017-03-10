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
    int sumNumbers(TreeNode *root) {
        if(root==NULL)  return 0;
        int sum=0,side=0;
        dfs(root,sum,side);
        return sum;
    }
    void dfs(TreeNode *root, int& sum, int& side){
        if(root->right==NULL&&root->left==NULL){
            side = side*10+root->val;
            sum += side;
            side = (side - root->val)/10;
            return;
        }

        if(root->left!=NULL){
            side = side*10+root->val;
            dfs(root->left,sum,side);
            side = (side - root->val)/10;
        }

        if(root->right!=NULL){
            side = side*10+root->val;
            dfs(root->right,sum,side);
            side = (side - root->val)/10;
        }
    }
};