class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int h = matrix.size();
        if(h==0)    return false;
        int w = matrix[0].size();
        int curx = w-1, cury = 0;
        bool res = false;
        while((curx>=0&&curx<w)&&(cury>=0&&cury<h)){
            if(matrix[cury][curx]==target){
                res = true;
                break;
            }
            else if(matrix[cury][curx]<target)  ++cury;
            else    --curx;
        }
        return res;
    }
};