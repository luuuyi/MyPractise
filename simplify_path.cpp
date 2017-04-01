//solution
class Solution {
public:
    string simplifyPath(string path) {
        int lens = path.size();
        vector<string> vec;
        string str;
        for(int i=0;i<lens;i++){
            if(path[i]=='/'){
                if(!str.empty()){
                    if(str==".");
                    else if(str==".."){
                        if(vec.empty());
                        else    vec.pop_back();
                    }
                    else    vec.push_back(str);
                    str.clear();
                }
            }
            else    str.push_back(path[i]);
        }
        if(!str.empty()){
            if(str==".");
            else if(str==".."){
                if(vec.empty());
                else    vec.pop_back();
            }
            else    vec.push_back(str);
            str.clear();
        }
        int lens_v = vec.size();
        string res;
        if(lens_v==0) res = "/";
        for(int i=0;i<lens_v;i++){
            res += "/" + vec[i];
        }
        return res;
    }
};