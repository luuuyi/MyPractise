class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<int, char>> stk;
        int lens = s.size();
        if(lens==0) return 0;
        for(int i=0;i<lens;i++){
            if(stk.empty()) stk.push(make_pair(i,s[i]));
            else{
                if(s[i]==')'&&stk.top().second=='(')    stk.pop();
                else    stk.push(make_pair(i,s[i]));
            }
        }
        int max_lens = 0,last = lens;
        while(!stk.empty()){
            if(last-stk.top().first-1>max_lens){
                max_lens = last-stk.top().first-1;
            }
            last = stk.top().first;
            stk.pop();
        }
        if(last>max_lens)   max_lens = last;
        return max_lens;
    }
};