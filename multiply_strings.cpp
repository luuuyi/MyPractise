class Solution {
public:
    string multiply(string num1, string num2) {
        int lens1 = num1.size(), lens2 = num2.size();
        if(lens1==0)    return num2;
        if(lens2==0)    return num1;

        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        vector<int> vecs(lens1+lens2+1,0);
        for(int i=0;i<lens2;i++){
            for(int j=0;j<lens1;j++){
                vecs[i+j] += (num2[i]-'0')*(num1[j]-'0');
            }
        }
        int upper = 0, vecs_lens = vecs.size();
        for(int i=0;i<vecs_lens;i++){
            int tmp = vecs[i]+upper;
            upper = tmp /10;
            vecs[i] = tmp % 10;
        }
        string ret;
        int right = vecs_lens-1;
        while(right>0){
            if(vecs[right]==0)   right--;
            else    break;
        }
        for(;right>=0;right--)  ret.push_back(vecs[right]+'0');
        return ret;
    }
};