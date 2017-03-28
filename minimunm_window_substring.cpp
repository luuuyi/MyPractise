//solution1
class Solution {
public:
    bool isContain(string& T, char ch){
        for(int i=0;i<T.size();i++){
            if(T[i]==ch)    return true;
        }
        return false;
    }

    string change(string& T){
        map<char,int> mp;
        for(int i=0;i<T.size();i++){
            ++mp[T[i]];
        }
        string res;
        for(auto k=mp.begin();k!=mp.end();k++){
            res.push_back(k->first);
        }
        return res;
    }

    string minWindow(string S, string T) {
        vector<char> chs;
        vector<int> indexs;
        T = change(T);
        string res;
        for(int i=0;i<S.size();i++){
            if(isContain(T,S[i])){
                chs.push_back(S[i]);
                indexs.push_back(i);
            }
        }
        if(chs.size()<T.size()) return res;
        int mini = 0x7fffffff;
        for(int i=T.size()-1;i<chs.size();i++){
            int i_tmp = i;
            map<char,int> mp;
            while(i_tmp>=0){
                ++mp[chs[i_tmp]];
                if(mp.size()==T.size()) break;
                --i_tmp;
            }
            if(mp.size()==T.size()){
                if(i-i_tmp+1<mini){
                    mini = i-i_tmp+1;
                    res = S.substr(indexs[i_tmp],indexs[i]-indexs[i_tmp]+1);
                }
            }
            mp.clear();
        }
        return res;
    }
};

//solution2
class Solution {
public:
    string minWindow(string S, string T) {
        map<char,int> mp;
        int T_lens = T.size();
        for(int i=0;i<T_lens;i++){
            ++mp[T[i]];
        }
        int right=0,left=0,S_lens = S.size(),count=0;
        string res;
        if(T_lens>S_lens)   return res;
        int min = 0x7fffffff;
        for(;right<S_lens;right++){
            if(mp.find(S[right])!=mp.end()){
                --mp[S[right]];
                if(mp[S[right]]>=0) count++;
                while(count==T_lens){
                    if(right-left+1<min){
                        min = right-left+1;
                        res = S.substr(left,min);
                    }
                    if(mp.find(S[left])!=mp.end()){
                        ++mp[S[left]];
                        if(mp[S[left]]>0) count--;
                    }
                    ++left;
                }
            }
        }
        return res;
    }
};