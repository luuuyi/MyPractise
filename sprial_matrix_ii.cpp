class Solution {
private:
    void spiralMatrix(vector<vector<int>>& res, int n){
        int n_tmp = n,x=0,y=0,count=1;
        while(n_tmp>0){
            if(n_tmp==1)    res[y][x] = count++;
            for(int i=0;i<n_tmp-1;i++){
                res[y][x+i] = count++;
            }
            x += n_tmp-1;
            for(int i=0;i<n_tmp-1;i++){
                res[y+i][x] = count++;
            }
            y += n_tmp-1;
            for(int i=0;i<n_tmp-1;i++){
                res[y][x-i] = count++;
            }
            x -= n_tmp-1;
            for(int i=0;i<n_tmp-1;i++){
                res[y-i][x] = count++;
            }
            y -= n_tmp-1;
            n_tmp -=2;++x;++y;
        }
    }
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int>> res;
        if(n==0)    return res;
        res.assign(n,vector<int>(n,0));
        spiralMatrix(res,n);
        return res;
    }
};