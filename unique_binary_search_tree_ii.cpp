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
private:
    vector<TreeNode *> generate(int start, int end){
        vector<TreeNode *> subset;
        if(start>end){
            subset.push_back(NULL);
            return subset;
        }
        for(int i=start;i<=end;i++){
            vector<TreeNode *> left_part = generate(start,i-1);
            vector<TreeNode *> right_part = generate(i+1,end);
            for(int j=0;j<left_part.size();j++){
                for(int k=0;k<right_part.size();k++){
                    TreeNode *root = new TreeNode(i);
                    root->left = left_part[j];
                    root->right = right_part[k];
                    subset.push_back(root);
                }
            }
        }
        return subset;
    }
public:
    vector<TreeNode *> generateTrees(int n) {
        if(n<1) return generate(1,0);
        else    return generate(1,n);
    }
};