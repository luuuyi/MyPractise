//solution1
class Solution {
public:
    bool isScramble(string s1, string s2) {
        int lens1 = s1.size(),lens2 = s2.size();
        if(lens1!=lens2)    return false;
        if(s1.compare(s2)==0)   return true;
        string tmp1 = s1, tmp2 = s2;
        sort(tmp1.begin(),tmp1.end());
        sort(tmp2.begin(),tmp2.end());
        if(tmp1.compare(tmp2)!=0)   return false;
        for(int i=1;i<lens1;i++){
            if(isScramble(s1.substr(0,i),s2.substr(0,i))&&isScramble(s1.substr(i),s2.substr(i)))    return true;
            if(isScramble(s1.substr(0,i),s2.substr(lens1-i))&&isScramble(s2.substr(0,lens1-i),s1.substr(i)))    return true;
        }
        return false;
    }
};

//solution2
class Solution {
public:
    bool isScramble(string s1, string s2) {
        int lens1 = s1.size(),lens2 = s2.size();
        if(lens1!=lens2)    return false;
        if(s1.compare(s2)==0)   return true;
        vector<vector<vector<bool>>> dp(lens1,vector<vector<bool>>(lens2,vector<bool>(lens1+1,false)));
        for(int i=0;i<lens1;i++){
            for(int j=0;j<lens2;j++){
                dp[i][j][1] = s1[i]==s2[j];
            }
        }
        for(int lens=2;lens<=lens1;lens++){
            for(int i=0;i<lens1-lens+1;i++){
                for(int j=0;j<lens2-lens+1;j++){
                    for(int k=1;k<lens;k++){
                        dp[i][j][lens] = dp[i][j][lens]||((dp[i][j][k]&&dp[i+k][j+k][lens-k])||(dp[i][j+lens-k][k]&&dp[i+k][j][lens-k]));
                    }
                }
            }
        }
        return dp[0][0][lens1];
    }
};
