class Solution {
public:
    int numDistinct(string S, string T) {
        int t = T.size();
        int s = S.size();
        vector<vector<int>> dp;
        for(int i=0;i<t+1;i++){
            if(i==0){
                vector<int> tmp(s+1,1);
                dp.push_back(tmp);
            }
            else{
                vector<int> tmp(s+1,0);
                dp.push_back(tmp);
            }
        }
        for(int i=1;i<t+1;i++){
            for(int j=1;j<s+1;j++){
                if(S[j-1]==T[i-1])  dp[i][j] = dp[i][j-1]+dp[i-1][j-1];
                else    dp[i][j] = dp[i][j-1];
            }
        }
        return dp[t][s];
    }
};