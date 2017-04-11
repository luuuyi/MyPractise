class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > res;
        int lens = num.size();
        if(lens==0) return res;
        sort(num.begin(),num.end());
        res.push_back(num);
        while(next_permutation(num.begin(),num.end())){
            res.push_back(num);
        }
        return res;
    }
};