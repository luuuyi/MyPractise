class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int lens = s.size();
        vector<string> ret
        if(lens == 0)   return ret;

        vector<int> dp(lens+1,0);
        dp[0] = 0xffffffff;
        for(int i=0;i<lens;i++){
            int n = 1,m = 0;
            for(int j =i;j<lens&&dp[i];j++){
                if(dict.find(s.substr(i,j-i+1))!=dict.end()){
                    dp[j+1] |= n<<m;
                    ++m;
                }
            }
        }
    }
};