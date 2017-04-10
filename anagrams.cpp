class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> res;
        int lens = strs.size();
        if(lens==0) return res;
        unordered_map<string,vector<int>> mp;
        for(int i=0;i<lens;i++){
            string tmp = strs[i];
            sort(tmp.begin(),tmp.end());
            mp[tmp].push_back(i);
        }
        for(auto k=mp.begin();k!=mp.end();k++){
            if(k->second.size()>=2){
                for(int j=0;j<k->second.size();j++)
                    res.push_back(strs[k->second[j]]);
            }
        }
        return res;
    }
};

//solution best
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> res;
        if(!strs.size())
            return res;
        unordered_map<string, int> hmap;             
        for(int i = 0; i < strs.size(); i++){
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            hmap[tmp]++;
        }
        for(int i = 0; i < strs.size(); i++){
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            if(hmap[tmp] >= 2){
                res.push_back(strs[i]);
            }
        }
        return res;
    }
};