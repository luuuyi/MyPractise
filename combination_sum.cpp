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
                my_permutation(candidates,lens,i,target,tmp,res,tmp_sum+candidates[i]);
                tmp.pop_back();
            }
            else    break;
        }
    }
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        int lens = candidates.size();
        vector<vector<int> > res;
        if(lens==0) return res;
        sort(candidates.begin(),candidates.end());
        vector<int> tmp;
        my_permutation(candidates,lens,0,target,tmp,res,0);
        return res;
    }
};