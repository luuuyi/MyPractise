class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int lens = digits.size();
        if(lens==0) return digits;
        int x = 1;
        for(int i=lens-1;i>=0;i--){
            if(x){
                if(digits[i]+1>9)   x=1;
                else    x=0;
                digits[i] = (digits[i]+1)%10;
            }
            else{
                break;
            }
        }
        if(x==1){
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};