class Solution {
public:
    bool isValid(string s) {
        int lens = s.size();
        if(lens&0x01)   return false;
        stack<char> stk;
        for(int i=0;i<lens;i++){
            if(stk.empty()||s[i]=='('||
            s[i]=='['||s[i]=='{') stk.push(s[i]);
            else{
                if(s[i]==')'){
                    if(stk.top()=='(')  stk.pop();
                    else    return false;
                }
                else if(s[i]==']'){
                    if(stk.top()=='[')  stk.pop();
                    else    return false;
                }
                else if(s[i]=='}'){
                    if(stk.top()=='{')  stk.pop();
                    else    return false;
                }
            }
        }
        if(stk.empty()) return true;
        else    return false;
    }
};