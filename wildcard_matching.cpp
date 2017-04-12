//out of time
class Solution {
private:
    bool wildCard(const char *s, const char *p){
        if((*s=='\0')&&(*p=='\0'))  return true;
        if(((*s!='\0')&&(*p=='\0'))||((*s=='\0')&&(*p!='\0')))  return false;
        if(*p=='?'){
            return wildCard(s+1,p+1);
        }
        else if(*p=='*'){
            return wildCard(s,p+1)||wildCard(s+1,p);
        }
        else{
            if((*s)==(*p))  return wildCard(s+1,p+1);
            else    return false;
        }
    }
public:
    bool isMatch(const char *s, const char *p) {
        int lens_s = strlen(s), lens_p = strlen(p);
        return wildCard(s,p);
    }
};

//dp solution
class Solution {
private:
    bool wildCard(const char *s, const char *p, int lens_s, int lens_p){
        vector<vector<bool>> dp(lens_s+1,vector<bool>(lens_p+1,true));
        for(int i=1;i<=lens_p;i++){
            if(p[i-1]=='*') dp[0][i] = dp[0][i-1];
            else    dp[0][i] = false;
        }
        for(int i=1;i<=lens_s;i++){
            dp[i][0] = false;
        }
        for(int i=1;i<=lens_s;i++){
            for(int j=1;j<=lens_p;j++){
                if(p[j-1]=='?') dp[i][j] = dp[i-1][j-1];
                else if(p[j-1]=='*')    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else{
                    if(p[j-1]==s[i-1])  dp[i][j] = dp[i-1][j-1];
                    else     dp[i][j] = false;
                }
            }
        }
        return dp[lens_s][lens_p];
    }
public:
    bool isMatch(const char *s, const char *p) {
        int lens_s = strlen(s), lens_p = strlen(p);
        //if(lens_s==0&&lens_p==0)    return true;
        //if(lens_s==0||lens_p==0)    return false;
        return wildCard(s,p,lens_s,lens_p);
    }
};