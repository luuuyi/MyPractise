class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int lens = s.size();
        if(lens==0) return false;

        vector<bool> dp(lens+1,false);
        dp[0]=true;
        for(int i=0;i<lens;i++){
            for(int j=i;dp[i]&&j<lens;j++){
                if(dict.find(s.substr(i,j-i+1))!=dict.end())    dp[j+1] = true;
            }
        }
        return dp[lens];
    }
};