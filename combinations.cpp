class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > ret;
        if(k>n) return ret;
        vector<int> tmp;
        solve(ret,1,n,k,tmp);
        return ret;
    }
    void solve(vector<vector<int> > &ret, int cur, int n, int k, vector<int> tmp){
        if(k==0){
            ret.push_back(tmp);
            return;
        }
        for(int i=cur;i<=n-k+1;i++){
            tmp.push_back(i);
            solve(ret,i+1,n,k-1,tmp);
            tmp.pop_back();
        }
    }
};