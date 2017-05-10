class Solution {
private:
    int findMaxCommonSubstr(string& word1, string& word2){
        int w1_lens = word1.size(), w2_lens = word2.size();
        vector<vector<int>> dp(w1_lens+1,vector<int>(w2_lens+1,0));
        for(int i=1;i<=w1_lens;i++){
            for(int j=1;j<=w2_lens;j++){
                if(word1[i-1]==word2[j-1])  dp[i][j] = dp[i-1][j-1] + 1;
                else    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[w1_lens][w2_lens];
    }

    int findMinOpera(string& word1, string& word2){
        int w1_lens = word1.size(), w2_lens = word2.size();
        vector<vector<int>> dp(w1_lens+1,vector<int>(w2_lens+1,0));
        for(int i=1;i<=w2_lens;i++) dp[0][i] = i;
        for(int i=1;i<=w1_lens;i++) dp[i][0] = i;
        for(int i=1;i<=w1_lens;i++){
            for(int j=1;j<=w2_lens;j++){
                if(word1[i-1]==word2[j-1])  dp[i][j] = dp[i-1][j-1];
                else    dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
            }
        }
        return dp[w1_lens][w2_lens];
    }
public:
    int minDistance(string word1, string word2) {
        int lens1 = word1.size(), lens2 = word2.size();
        if(lens1==0)    return lens2;
        if(lens2==0)    return lens1;
        int maxCommon = findMinOpera(word1,word2);
        return maxCommon;
    }
};