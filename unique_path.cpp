//solution1
class Solution {
private:
    int recursive(int m, int n){
        if(m==1||n==1)  return 1;
        return recursive(m-1,n) + recursive(m,n-1);
    }
public:
    int uniquePaths(int m, int n) {
        if(m==0||n==0)  return 0;
        return recursive(m,n);
    }
};

//solution2
class Solution {
private:
    int dpSolver(int m, int n){
        vector<vector<int>> dp(m,vector<int>(n,1));
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        }
        return dp[0][0];
    }
public:
    int uniquePaths(int m, int n) {
        if(m==0||n==0)  return 0;
        return dpSolver(m,n);
    }
};