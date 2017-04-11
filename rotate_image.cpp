class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        if(n==0)    return ;
        vector<vector<int> > tmp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                tmp[j][n-1-i] = matrix[i][j];
            }
        }
        matrix.assign(tmp.begin(),tmp.end());
        return;
    }
};