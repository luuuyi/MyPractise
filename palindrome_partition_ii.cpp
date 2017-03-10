class Solution {
public:
    int minCut(string s) {
        int lens = s.size();
        if(lens == 0)   return 0;

        vector<int> dp(lens);
        for(int i=0;i<lens;i++){
            dp[i] = isPalindrome(s.substr(0,i+1))?0:dp[i-1]+1;
            for(int j=1;j<i;j++){
                if(isPalindrome(s.substr(j,i-j+1)))
                    dp[i] = min(dp[j-1]+1,dp[i]);
            }
        }
        return dp[lens-1];
    }
    bool isPalindrome(string s){
        int lens = s.size();
        int mid = lens / 2;
        int left = 0, right = 0;
        if(lens&0x01){
            left = mid-1;
            right = mid+1;
            while(left<right&&left>=0&&right<lens){
                if(s[left]!=s[right])   return false;
                --left;
                ++right;
            }
            return true;
        }
        else{
            right = mid;
            left = mid-1;
            while(left<right&&left>=0&&right<lens){
                if(s[left]!=s[right])   return false;
                --left;
                ++right;
            }
            return true;
        }
    }
};