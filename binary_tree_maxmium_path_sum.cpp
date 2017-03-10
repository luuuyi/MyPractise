/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//All positive number
class Solution {
public:
    int maxPathSum(TreeNode *root) {
        if(root==NULL)  return 0;
        
        int sum = 0;
        int max = 0x80000000,cur=0;
        if(root->left){
            dfsFind(root->left,cur,max);
            sum += max;
        }
        cur=0;
        max = 0x80000000;
        if(root->right){
            dfsFind(root->right,cur,max);
            sum += max;
        }
        return sum+root->val;
    }

    void dfsFind(TreeNode *root,int cur,int& max){
        if(root->left==NULL&&root->right==NULL){
            cur += root->val;
            if(cur>max) max = cur;
            cur -= root->val;
        }
        else{
            if(root->left)  dfsFind(root->left,cur+root->val,max);
            if(root->right)  dfsFind(root->right,cur+root->val,max);
        }
    }
};

//solution
class Solution {
public:
    int maxPathSum(TreeNode *root) {
        int max_n = 0x80000000;
        int x = findResult(root,max_n);
        return max_n;
    }

    int findResult(TreeNode *root, int& max_n){
        if(root==NULL)  return 0;
        int left = max(0,findResult(root->left,max_n));
        int right = max(0,findResult(root->right,max_n));
        max_n = max(right+left+root->val,max_n);
        return max(right+root->val,left+root->val);
    }
};