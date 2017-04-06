//out of time
class Solution {
private:
    bool isNotContain(string &tmp, int n){
        int lens = tmp.size();
        for(int i=0;i<lens;i++){
            if((tmp[i]-'0')==n) return false;
        }
        return true;
    }
    void permutation(int n, int cur, int& times, int k, string &res, string& tmp){
        if(cur>=n){
            ++times;
            if(times == k)  res = tmp;
            return;
        }
        for(int i=0;i<n;i++){
            if(times<k&&isNotContain(tmp,i+1)){
                tmp.push_back('0'+i+1);
                permutation(n,cur+1,times,k,res,tmp);
                tmp.pop_back();
            }
        }
    }
public:
    string getPermutation(int n, int k) {
        string res;
        if(n==0||k==0)  return res;
        string tmp;
        int times = 0;
        permutation(n,0,times,k,res,tmp);
        return res;
    }
};

//solution STL
class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        if(n==0||k==0)  return res;
        for(int i=1;i<=n;i++)   res.push_back('0'+i);
        int k_tmp = k-1;
        while(k_tmp--){
            next_permutation(res.begin(),res.end());
        }
        return res;
    }
};

//solution smart
class Solution {
private:
    int factorial(int n){
        int res = 1;
        for(int i=1;i<=n;i++)   res *= i;
        return res;
    }
public:
    string getPermutation(int n, int k) {
        string res;
        if(n==0||k==0)  return res;
        for(int i=1;i<=n;i++)   res.push_back('0'+i);
        string result;
        if(k==1)    return res;
        int k_tmp = k-1, n_tmp = n-1;
        for(int i=0;i<n-1;i++,n_tmp--){
            int x = k_tmp % factorial(n_tmp);
            int y = k_tmp / factorial(n_tmp);
            k_tmp = x;
            auto k =  res.begin()+y;
            result.push_back(*k);
            res.erase(k);
        }
        return result;
    }
};