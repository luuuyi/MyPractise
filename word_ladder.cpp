class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if(start.size()!=end.size())    return 0;
        if(start.size()==0||end.size()==0)  return 0;

        queue<string> que;que.push(start);
        dict.erase(start);
        int count = 1, level = 1;
        while(!dict.empty()&&!que.empty()){
            string tmp = que.front();
            que.pop(); --count;
            for(int i=0;i<tmp.size();i++){
                string another_tmp = tmp;
                for(char a = 'a';a<='z';a++){
                    if(another_tmp[i]==a)   continue;
                    another_tmp[i]=a;
                    if(another_tmp==end)    return level+1;
                    if(dict.find(another_tmp)!=dict.end()){
                        que.push(another_tmp);
                        dict.erase(another_tmp);
                    }
                }
            }
            if(count==0){
                count = que.size();
                ++level;
            }
        }
        return 0;
    }
};