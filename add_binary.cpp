class Solution {
public:
    string addBinary(string a, string b) {
        string str1 = a,str2 = b;
        int lens_1 = str1.size(), lens_2 = str2.size();
        if(lens_1==0)    return b;
        int i=lens_1, j= lens_2;
        int add_i=0,x=0;
        string res;
        while(i&&j){
            add_i = (str1[i-1]-'0') + (str2[j-1]-'0');
            add_i += (x==0?0:1);
            if(x==1)    x=0;
            char tmp='\0';
            if(add_i>1){
                tmp = (add_i%2)+'0';
                x=1;
            }
            else{
                tmp = add_i+'0';
            }
            res.push_back(tmp);
            add_i=0;--i;--j;
        }
        while(i){
            if(x==1){
                add_i = (str1[i-1] - '0')+x;
                x=0;
                char tmp='\0';
                if(add_i>1){
                    tmp = (add_i%2)+'0';
                    x=1;
                }
                else{
                    tmp = add_i+'0';
                }
                res.push_back(tmp);
            }
            else{
                res.push_back(str1[i-1]);
            }
            --i;
        }
        while(j){
            if(x==1){
                add_i = (str2[j-1] - '0')+x;
                x=0;
                char tmp='\0';
                if(add_i>1){
                    tmp = (add_i%2)+'0';
                    x=1;
                }
                else{
                    tmp = add_i+'0';
                }
                res.push_back(tmp);
            }
            else{
                res.push_back(str2[j-1]);
            }
            --j;
        }
        if(x==1)    res.push_back('1');
        reverse(res.begin(),res.end());
        return res;
    }
};

//solution
class Solution {
public:
    char addBit(char c1, char c2, int &carry){
        int result=c1-'0'+c2-'0'+carry;
        carry=result/2;
        return result%2?'1':'0';
    }
    string addBinary(string a, string b) {
        int ind1=a.size()-1, ind2=b.size()-1;
        int carry=0;
        deque<char> c_deque;
        string ret;
        char c1; char c2;
        while(ind1>=0||ind2>=0){
            c1=(ind1)<0?'0':a[ind1--];
            c2=(ind2)<0?'0':b[ind2--];
            c_deque.push_front(addBit(c1, c2, carry));
        }
        if(carry)
            c_deque.push_front('1');
        for(int i=0; i<c_deque.size(); ++i)
            ret.push_back(c_deque[i]);
        return ret;
    }
};