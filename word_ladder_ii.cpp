class Solution {
private:
    void permutationFind(string& start, string& end, vector<string> vecs, vector<string>& tmp, unordered_set<string> &dict,vector<vector<string>>& ret){
        if(start==end||dict.empty()){

        }
        for(int i=0;i<vecs.size();i++){
            string tmp = vecs[i];
            
        }
    }
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        int s_lens = start.size(), e_size = end.size();
        if(s_lens!=e_lens)  return vector<vector<string>>();
        if(s_lens==0||e_lens==0)    return vector<vector<string>>();
        queue<string> que; que.push(start);
        dict.erase(start);
        int level = 0, count = 1;
        vector<string> tmp;
        vector<vector<string>> ret;
        while(!dict.empty()&&!que.empty()){
            string tmp = que.front();que.pop();
            count--;
            for(int i=0;i<tmp.size();i++){
                string another_tmp = tmp;
                for(char j='a';j<='z';j++){
                    if(another_tmp[i]==j)   continue;
                    another_tmp[i]=j;
                    if(dict.find(another_tmp)!=dict.end()){
                        que.push(another_tmp);
                        dict.erase(another_tmp);
                    }
                }
            }
            if(count==0){
                ++level;
                count = que.size();
            }
        }
    }
};