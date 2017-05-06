class Solution {
private:
    void dfs(string start, string end, vector<string>& tmp, vector<vector<string>>& ret, unordered_map<string, vector<string>>& mp){
        if(end==start){
            //reverse(tmp.begin(),tmp.end());
            ret.push_back(vector<string>(tmp.rbegin(),tmp.rend()));
            return;
        }
        int lens = mp[end].size();
        for(int i=0;i<lens;i++){
            tmp.push_back(mp[end][i]);
            dfs(start,mp[end][i],tmp,ret,mp);
            tmp.pop_back();
        }
    }
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        int s_lens = start.size(), e_lens = end.size();
        if(s_lens!=e_lens)  return vector<vector<string>>();
        if(s_lens==0||e_lens==0)    return vector<vector<string>>();
        unordered_map<string, vector<string>> mp;
        unordered_set<string> has; has.insert(start);
        dict.erase(start); dict.insert(end);
        while(!dict.empty()&&!has.empty()){
            unordered_set<string> tmp;
            for(auto k=has.begin();k!=has.end();k++){
                string word = *k;
                for(int i=0;i<word.size();i++){
                    string another_tmp = word;
                    for(char j='a';j<='z';j++){
                        if(another_tmp[i]==j)   continue;
                        another_tmp[i]=j;
                        if(dict.find(another_tmp)!=dict.end()){
                            tmp.insert(another_tmp);
                            mp[another_tmp].push_back(word);
                        }
                    }
                }
            }
            for(auto k=tmp.begin();k!=tmp.end();k++){
                dict.erase(*k);
            }
            has = tmp;
        }
        if(mp.find(end)!=mp.end()){
            vector<string> tmp; tmp.push_back(end);
            vector<vector<string>> ret;
            dfs(start,end,tmp,ret,mp);
            return ret;
        }
        else    return vector<vector<string>>();
    }
};

测试用例:
"hot","dog",["hot","cog","dog","tot","hog","hop","pot","dot"]

对应输出应该为:

[["hot","dot","dog"],["hot","hog","dog"]]

你的输出为:

[["hot","hog","dog"],["hot","dot","hot"]]