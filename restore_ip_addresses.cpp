class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int s_lens = s.size();
        vector<string> ret;
        if(s_lens==0)   return ret;
        int valid = 4;
        vector<string> tmp;
        spliteString(s,valid,ret,tmp);
        return ret;
    }
    void spliteString(string s,int valid,vector<string>& ret,vector<string>& tmp){
        if(valid==0&&s.size()==0){
            string tmp_s;
            for(int i=0;i<tmp.size()-1;i++){
                tmp_s.append(tmp[i]);
                tmp_s += ".";
            }
            tmp_s.append(tmp[tmp.size()-1]);
            ret.push_back(tmp_s);
            return;
        }
        int lens = s.size();
        for(int i=0;i<lens;i++){
            string sub_s = s.substr(0,i+1);
            if(isValid(sub_s)){
                tmp.push_back(sub_s);
                spliteString(s.substr(i+1),valid-1,ret,tmp);
                tmp.pop_back();
            }
        }
        return ;
    }
    bool isValid(string s){
        int num = atoi(s.c_str());
        if(num>=0&&num<=255){
            if(s[0]=='0'&&num>0)    return false;
            if(s[0]=='0'&&s.size()!=1)    return false;
            return true;
        }    
        else    return false;
    }
};

//solution 2
class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> ips;
        rec(s, 0, 0, "", ips);
        return ips;
    }
    void rec(const string& s, int i, int m, string ip, vector<string>& ips)//m :[0 , 3]
    {
        for (int k = 1; k <=3; k++)
        {
            int left = s.size() - i;
            if (left > 3 * (4 - m)) break;
            if (left < (4 - m)) break;
            string sub = s.substr(i, k);
            int val = atoi(sub.c_str());
            if (k > 1 && s[i] == '0') break;
            if (val > 255) break;
            if (m < 3)
            {
                rec(s, i + k, m + 1, ip + sub + ".", ips);
            }
            if(m == 3 && i + k == s.size()) ips.push_back(ip+ sub);
        }
    }
};