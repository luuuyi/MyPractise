class Solution {
public:
    int candy(vector<int> &ratings) {
        int lens = ratings.size();
        if(lens == 0)   return 0;

        vector<int> candys(lens,1);
        for(int i = 0;i<lens-1;i++){
            if(ratings[i]<ratings[i+1]){
                candys[i+1] = candys[i] + 1;
            }
        }
        int sum = 0;
        for(int i = lens-1;i>0;i--){
            sum += candys[i];
            if(ratings[i]<ratings[i-1]&&candys[i]>=candys[i-1]){
                candys[i-1] = candys[i] + 1;
            }
        }
        sum += candys[0];
        return sum;
    }
};