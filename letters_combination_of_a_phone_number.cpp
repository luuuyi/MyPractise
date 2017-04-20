class Solution {
private:
    vector<string> init(){
        return vector<string>({
            "","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
        });
    }

    void myPermutation(string& digits,vector<string>& tables,int cur, int lens, string tmp,vector<string>& res){
        if(cur>=lens){
            res.push_back(tmp);
            return;
        }
        for(int i=0;i<tables[digits[cur]-'1'].size();i++){
            tmp.push_back(tables[digits[cur]-'1'][i]);
            myPermutation(digits,tables,cur+1,lens,tmp,res);
            tmp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        int lens = digits.size();
        if(lens==0){
            res.push_back(digits);
            return res;
        }
        string tmp;
        vector<string> tables = init();
        myPermutation(digits,tables,0,lens,tmp,res);
        return res;
    }
};