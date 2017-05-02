class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int s_lens = strlen(s);
        int p_lens = strlen(p);
        vector<vector<bool>> dp(s_lens+1,vector<bool>(p_lens+1,false));
        dp[0][0] = true;
        for(int i=1;i<=p_lens;i++){
            if(p[i-1]=='*'&&i>1) dp[0][i] = dp[0][i-2];
        }
        for(int i=1;i<=s_lens;i++){
            for(int j=1;j<=p_lens;j++){
                if(j>1&&p[j-1]=='*')  dp[i][j] = dp[i][j-2]||((s[i-1]==p[j-2]||p[j-2]=='.')&&dp[i-1][j]);
                else    dp[i][j] = (s[i-1]==p[j-1]||p[j-1]=='.')&&dp[i-1][j-1];
            }
        }
        return dp[s_lens][p_lens];
    }
};