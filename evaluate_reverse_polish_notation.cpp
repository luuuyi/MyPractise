#include <sstream>

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        int lens = tokens.size();
        if(lens == 0)   return 0;

        stack<int> stk;
        int result = 0;
        for(int i=0;i<lens;i++){
            string symbol = tokens[i];
            if(symbol =="+"){
                int right = stk.top();
                stk.pop();
                int left = stk.top();
                stk.pop();
                stk.push(left + right);
            }
            else if(symbol=="-"){
                int right = stk.top();
                stk.pop();
                int left = stk.top();
                stk.pop();
                stk.push(left - right);
            }
            else if(symbol=="*"){
                int right = stk.top();
                stk.pop();
                int left = stk.top();
                stk.pop();
                stk.push(left * right);
            }
            else if(symbol=="/"){
                int right = stk.top();
                stk.pop();
                int left = stk.top();
                stk.pop();
                stk.push(left / right);
            }
            else{
                int nums = 0;
                stringstream ss;
                ss << symbol;
                ss >> nums;
                stk.push(nums);
            }
        }
        return stk.top();
    }
};