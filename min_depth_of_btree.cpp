class Solution {
public:
    int run(TreeNode *root) {
        if(root == NULL)   return 0;
        int min = 0x7fffffff;
        dfs(root,1,min);
        return min;
    }

    void dfs(TreeNode *root, int depth, int& min){
        if(root->right==NULL&&root->left==NULL){
            if(depth < min) min = depth;
            return;
        }

        if(root->left!=NULL){
            dfs(root->left,depth+1,min);
        }

        if(root->right!=NULL){
            dfs(root->right,depth+1,min);
        }
    }
};