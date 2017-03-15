//Solution1
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int s1_lens = s1.size(), s2_lens = s2.size(),
        s3_lens = s3.size();
        if(s1_lens+s2_lens!=s3_lens)    return false;
        int i=0,j=0,k=0;
        while(i<s1_lens&&j<s2_lens){
            if(s1[i]==s3[k]&&s2[j]==s3[k]){
                return isInterleave(s1.substr(i+1),s2.substr(j),s3.substr(k+1))||
                isInterleave(s1.substr(i),s2.substr(j+1),s3.substr(k+1));
            }
            if(s1[i]==s3[k]||s2[j]==s3[k]){
                if(s1[i]==s3[k]){
                    ++i;++k;continue;
                }
                else{
                    ++j;++k;continue;
                }
            }
            return false;
        }
        while(i<s1_lens){
            if(s1[i++]!=s3[k++])    return false;
        }
        while(j<s2_lens){
            if(s2[j++]!=s3[k++])    return false;
        }
        return true;
    }
};

//Solution2
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int s1_lens = s1.size(), s2_lens = s2.size(),
        s3_lens = s3.size();
        if(s1_lens+s2_lens!=s3_lens)    return false;
        vector<vector<bool>> dp(s1_lens+1,vector<bool>(s2_lens+1,false));
        for(int i=0;i<s1_lens+1;i++){
            for(int j=0;j<s2_lens+1;j++){
                if(i==0&&j==0)  dp[i][j] = true;
                else if(i==0)   dp[i][j] = (s2[j-1]==s3[j-1]) && dp[i][j-1];
                else if(j==0)   dp[i][j] = (s1[i-1]==s3[i-1]) && dp[i-1][j];
                else    dp[i][j] = ((s2[j-1]==s3[i+j-1]) && dp[i][j-1]) || ((s1[i-1]==s3[i+j-1]) && dp[i-1][j]);
            }
        }
        return dp[s1_lens][s2_lens];
    }
};