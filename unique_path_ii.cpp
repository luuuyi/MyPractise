class Solution {
private:
    int dpSolver(vector<vector<int> > &obstacleGrid, int m, int n){
        vector<vector<int>> dp(m,vector<int>(n,0));
        if(obstacleGrid[m-1][n-1]==1) return 0;
        for(int i=m-1;i>=0;i--){
            if(obstacleGrid[i][n-1]==1){
                dp[i][n-1] = 0;
                break;
            }
            else    dp[i][n-1] = 1;
        }
        for(int i=n-1;i>=0;i--){
            if(obstacleGrid[m-1][i]==1){
                dp[m-1][i] = 0;
                break;
            }
            else    dp[m-1][i] = 1;
        }
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                if(obstacleGrid[i][j]==1)   dp[i][j] = 0;
                else    dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        }
        return dp[0][0];
    }
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int h = obstacleGrid.size();
        if(h==0)    return 0;
        int w = obstacleGrid[0].size();
        return dpSolver(obstacleGrid,h,w);
    }
};

