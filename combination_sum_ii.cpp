class Solution {
private:
    void my_permutation(vector<int> &candidates, int lens, int cur, int target, vector<int> tmp, vector<vector<int> >& res, int tmp_sum){
        if(cur>=lens||tmp_sum==target){
            if(tmp_sum==target){
               res.push_back(tmp);
            }
            return;
        }
        for(int i=cur;i<lens;i++){
            if(tmp_sum+candidates[i]<=target){
                tmp.push_back(candidates[i]);
                my_permutation(candidates,lens,i+1,target,tmp,res,tmp_sum+candidates[i]);
                tmp.pop_back();
            }
            else    break;
        }
    }

    void eraseDuplicate(vector<vector<int> >& res){
        map<vector<int>,int> mp;
        int lens = res.size();
        for(auto i=res.begin();i!=res.end();){
            if(mp.find(*i)!=mp.end()){
                i = res.erase(i);
            }
            else{
                mp[*i] = 1;
                ++i;
            }
        }
    }
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        int lens = num.size();
        vector<vector<int> > res;
        if(lens==0) return res;
        sort(num.begin(),num.end());
        vector<int> tmp;
        my_permutation(num,lens,0,target,tmp,res,0);
        eraseDuplicate(res);
        return res;
    }
};