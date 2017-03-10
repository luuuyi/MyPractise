
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res;
        if(numRows==0)     return res;

        vector<int> tmp(1,0);
        tmp[0] = 1;
        res.push_back(tmp);
        for(int i=1;i<numRows;i++){
            vector<int> tmp(i+1,0);
            for(int j=0;j<i+1;j++){
                int left = j-1<0?0:res[i-1][j-1];
                int right = j>=i?0:res[i-1][j];
                tmp[j] = left + right;
            }
            res.push_back(tmp);
        }
        return res;
    }
};