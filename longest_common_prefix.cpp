class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int lens = strs.size();
        if(lens==0)	return "";
        if(lens==1)	return strs[0];
        string tmp = strs[0];
        int min_val = 0x7fffffff;
        for(int i=1;i<lens;i++){
            int tmp_common = 0;
        	for(int j=0;j<tmp.size()&&j<strs[i].size();j++){
                if(tmp[j]==strs[i][j])	++tmp_common;
                else    break;
            }
            min_val = min(min_val,tmp_common);
        }
        if(min_val!=0)  return tmp.substr(0,min_val);
        else    return "";
    }
};