class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > ret;
        int lens = S.size();
        if(lens==0) return ret;
        sort(S.begin(),S.end());
        vector<int> null;
        ret.push_back(null);
        map<vector<int>,int> marks;
        ++marks[null];
        for(int i=0;i<lens;i++){
            int lens_tmp = ret.size();
            for(int j=0;j<lens_tmp;j++){
                vector<int> tmp_vec(ret[j].begin(),ret[j].end());
                tmp_vec.push_back(S[i]);
                ++marks[tmp_vec];
                if(marks[tmp_vec]<=1)  ret.push_back(tmp_vec);
            }
        }
        return ret;
    }
};

//good solution
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > result;
        if(S.size() == 0)
            return result;
        vector<int> collection;
        sort(S.begin(), S.end());
        helper(S, 0, collection, result);
         
        return result;
    }
     
    void helper(vector<int> S, int startIndex, vector<int> collection, vector<vector<int> >& result)
    {
        result.push_back(collection);
         
        for(int i = startIndex; i < S.size(); i++)
        {
            if(i != startIndex && S[i] == S[i - 1]) continue;
            collection.push_back(S[i]);
            helper(S, i + 1, collection, result);
            collection.pop_back();
        }
    }
};