
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1,1);
        for(int i=1;i<=rowIndex;i++){
            for(int j=i;j>=0;j--){
                int left = j-1<0?0:res[j-1];
                int right = j>=i?0:res[j];
                res[j] = left + right;
            }
        }
        return res;
    }
};


[1,2,2]