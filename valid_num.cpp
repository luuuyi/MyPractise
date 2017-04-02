class Solution {
public:
    bool isNumber(const char *s) {
        int n = strlen(s);
        int i = 0;
        bool sym_flag=true, e_flag = true, dot_flag=true,num_flag=true;
        while(i<n){
            if(*(s+i)=='+'||*(s+i)=='-'){
                if(i!=0||!sym_flag)    return false;
                sym_flag = false;
            }
            else if(*(s+i)=='e'||*(s+i)=='E'){
                if(!sym_flag||i==0) return false;
                e_flag = false;
            }
            else if(*(s+i)=='.'){
                if(!dot_flag||i==0) return false;
                dot_flag = false;
            }
            else if(*(s+i)==' '){
                if(i!=0){
                    sym_flag=false;e_flag = false;dot_flag=false;num_flag=false;
                }
            }
            else if(*(s+i)>='0'&&*(s+i)<='9'){
                if(!num_flag)   return false;
            }
            else    return false;
            ++i;
        }
        return num_flag;
    }
};