class Solution {
public:
    int numDecodings(string s) {
        int lens = s.size();
        if(lens==0) return 0;
        vector<int> dp(lens+1,1);
        if(s[0]=='0')    dp[1] = 0;
        for(int i=1;i<lens;i++){
            if(s[i-1]>='1'&&s[i-1]<='2'){
                if(s[i-1]=='2'){
                    if(s[i]>='7')   dp[i+1] = dp[i];
                    else if(s[i]>='1'&&s[i]<='6')    dp[i+1] = dp[i]+dp[i-1];
                    else    dp[i+1] = dp[i-1];
                }
                else{
                    if(s[i]!='0')   dp[i+1] = dp[i]+dp[i-1];
                    else    dp[i+1] = dp[i-1];
                }
            }
            else if(s[i-1]>='3'&&s[i-1]<='9'){
                if(s[i]!='0')   dp[i+1] = dp[i];
                else    dp[i+1] = 0;
            }
            else{
                if(s[i]!='0')   dp[i+1] = dp[i];
                else    dp[i+1] = 0;
            }
        }
        return dp[lens];
    }
};
