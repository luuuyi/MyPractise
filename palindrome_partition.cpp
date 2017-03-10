class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        vector<string> vec;
        int lens = s.size();
        if(lens == 0)   return ret;

        getResult(s,vec,ret);
        return ret;
    }

    void getResult(string s, vector<string> &vec, vector<vector<string>> &ret){
        int lens = s.size();
        if(lens<1){
            ret.push_back(vec);
            return;
        }
        int i;
        for(i=0;i<lens;i++){
            if(isPalindrome(s.substr(0,i+1))){
                vec.push_back(s.substr(0,i+1));
                getResult(s.substr(i+1),vec,ret);
                vec.pop_back();
            }
        }
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