class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int rows = triangle.size();
        if(rows==0) return 0;
        int cols = triangle[rows-1].size();
        if(cols==0) return 0;

        vector<int> dp(cols+1,0);
        for(int i=rows-1;i>=0;i--){
            for(int j=0;j<i+1;j++){
                dp[j] = (triangle[i][j]+dp[j])<(triangle[i][j]+dp[j+1])?triangle[i][j]+dp[j]:triangle[i][j]+dp[j+1];
            }
        }
        return dp[0];
    }
};