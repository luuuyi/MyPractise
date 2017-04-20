class Solution {
private:
    bool isValid(string& str){
        stack<char> stk;
        for(int i=0;i<str.size();i++){
            if(stk.empty()){ 
                if(str[i]=='(') stk.push(str[i]);
                else    return false;
            }
            else{
                if(str[i]=='(') stk.push(str[i]);
                else{
                    if(stk.top()=='(')  stk.pop();
                    else    return false;
                }
            }
        }
        return true;
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n==0)    return res;
        string patten1, patten2;
        for(int i=0;i<n;i++){
            patten1 += "(";
            patten2 += ")";
        }
        string patten = patten1 + patten2;
        res.push_back(patten);
        while(next_permutation(patten.begin(),patten.end())){
            if(isValid(patten)) res.push_back(patten);
        }
        return res;
    }
};