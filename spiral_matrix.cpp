class Solution {
private:
    vector<int> spiralMatrix(vector<vector<int>>& matrix, int h, int w){
        int h_tmp = h,w_tmp = w,x=0,y=0;
        vector<int> res;
        while(h_tmp>0&&w_tmp>0){
            if(h_tmp==1&&w_tmp==1)  res.push_back(matrix[y][x]);
            if(h_tmp==1&&w_tmp!=1){
                for(int i=0;i<w_tmp;i++){
                    res.push_back(matrix[y][x+i]);
                }
            }
            if(w_tmp==1&&h_tmp!=1){
                for(int i=0;i<h_tmp;i++){
                    res.push_back(matrix[y+i][x]);
                }
            }
            if(h_tmp!=1&&w_tmp!=1){
                for(int i=0;i<w_tmp-1;i++){
                    res.push_back(matrix[y][x+i]);
                }
                x += w_tmp-1;
                for(int i=0;i<h_tmp-1;i++){
                    res.push_back(matrix[y+i][x]);
                }
                y += h_tmp-1;
                for(int i=0;i<w_tmp-1;i++){
                    res.push_back(matrix[y][x-i]);
                }
                x -= w_tmp-1;
                for(int i=0;i<h_tmp-1;i++){
                    res.push_back(matrix[y-i][x]);
                }
                y -= h_tmp-1;
            }
            w_tmp -=2;h_tmp -=2;++x;++y;
        }
        return res;
    }
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        int h = matrix.size();
        if(h==0)    return res;
        int w = matrix[0].size();
        return spiralMatrix(matrix,h,w);
    }
};