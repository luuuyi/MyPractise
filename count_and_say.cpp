class Solution {
private:
    string countString(string& str){
        int lens = str.size();
        string res;
        int start=0,size=1;
        for(int i=0;i<lens-1;i++){
            if(str[i+1]==str[i]){
                ++size;
            }
            else{
                res += to_string(size) + str[start];
                start = i+1;
                size = 1;
            }
        }
        res += to_string(size) + str[start];
        return res;
    }
public:
    string countAndSay(int n) {
        int start = 1;
        string str_n = to_string(start);
        int n_tmp = n-1;
        while(n_tmp--){
            string tmp = countString(str_n);
            str_n = tmp;
        }
        return str_n;
    }
};
                                                                                                                                                                                                                                           