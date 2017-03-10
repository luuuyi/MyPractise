class Solution {
public:
    bool isPalindrome(string s) {
        int lens = s.size();
        if(lens==0) return true;
        string tmp;
        for(int i=0;i<lens;i++){
            if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='0'&&s[i]<='9')){
                if(s[i]>='A'&&s[i]<='Z'){
                    tmp.push_back(s[i]-'A'+'a');
                }
                else    tmp.push_back(s[i]);
            }
        }
        return palindrome(tmp);
    }
    bool palindrome(string s){
        int lens = s.size();
        if(lens==0) return true;

        int left = 0, right = lens-1;
        while(left<=right){
            if(s[left]!=s[right])   return false;
            ++left;--right;
        }
        return true;
    }
};