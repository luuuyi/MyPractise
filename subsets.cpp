class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > ret;
        if(S.size()==0) return ret;
        sort(S.begin(),S.end());
        ret.push_back(vector<int>());
        for(int i=0;i<S.size();i++){
            vector<vector<int> > tmp;
            for(int j=0;j<ret.size();j++){
                vector<int> vec(ret[j].begin(),ret[j].end());
                vec.push_back(S[i]);
                tmp.push_back(vec);
            }
            ret.insert(ret.end(),tmp.begin(),tmp.end());
            tmp.clear();
        }
        return ret;
    }
};