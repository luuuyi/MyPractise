class Solution {
private:
    void changeMatrix(vector<vector<int> > &matrix, vector<int> point){
        int h = matrix.size();
        int w = matrix[0].size();
        for(int i=0;i<w;i++)    matrix[point[0]][i] = 0;
        for(int i=0;i<h;i++)    matrix[i][point[1]] = 0;
        return;
    }
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int h = matrix.size();
        if(h==0)    return;
        int w = matrix[0].size();
        vector<vector<int>> points;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(matrix[i][j]==0){
                    vector<int> tmp({i,j});
                    points.push_back(tmp);
                }
            }
        }
        int lens = points.size();
        for(int i=0;i<lens;i++) changeMatrix(matrix,points[i]);
        return;
    }
};