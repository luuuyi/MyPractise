class Solution {
private:
    bool isValid(vector<int>& pos, int col, int rows){
        for(int i=0;i<rows;i++){
            if(col == pos[i] || abs(col - pos[i]) == abs(rows - i))   return false;
        }
        return true;
    }

    void solveNQueen(vector<vector<string> > &res, int rows, int n, vector<int> &pos){
        if(rows>=n){
            vector<string> tmp_str;
            for(int i=0;i<n;i++){
                string tmp(n,'.');
                tmp[pos[i]] = 'Q';
                tmp_str.push_back(tmp);
            }
            res.push_back(tmp_str);
            return;
        }
        for(int i=0;i<n;i++){
            if(isValid(pos,i,rows)){
                pos[rows] = i;
                solveNQueen(res,rows+1,n,pos);
                pos[rows] = -1;
            }
        }
    }
public:
    vector<vector<string> > solveNQueens(int n) {
        if(n==0)    return vector<vector<string> >();
        vector<vector<string> > res;
        vector<int> pos(n,-1);
        solveNQueen(res,0,n,pos);
        return res;
    }
};