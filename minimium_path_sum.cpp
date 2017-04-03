class Solution {
private:
    int dpSolver(vector<vector<int> > &grid,int h, int w){
        vector<vector<int>> dp(h+1,vector<int>(w+1,0));
        for(int i=1;i<=w;i++)   dp[1][i] = grid[0][i-1] + dp[1][i-1];
        for(int i=1;i<=h;i++)   dp[i][1] = grid[i-1][0] + dp[i-1][1];
        for(int i=2;i<=h;i++){
            for(int j=2;j<=w;j++){
                dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i-1][j-1];
            }
        }
        return dp[h][w];
    }
public:
    int minPathSum(vector<vector<int> > &grid) {
        int h = grid.size();
        if(h==0)    return 0;
        int w = grid[0].size();
        return dpSolver(grid,h,w);
    }
};