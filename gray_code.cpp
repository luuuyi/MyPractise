class Solution {
public:
    vector<int> grayCode(int n) {
        if(n==0)    return vector<int>();
        vector<int> ret({0,1});
        for(int i=2;i<=n;i++){
            vector<int> tmp(ret.begin(),ret.end());
            int lens = ret.size();
            int pattern = 1; pattern <<= (i-1);
            for(int j=lens-1;j>=0;j--){
                tmp.push_back(ret[j]|pattern);
            }
            ret.assign(tmp.begin(),tmp.end());
        }
        return ret;
    }
};