//two-pass solution
class Solution {
public:
    void sortColors(int A[], int n) {
        if(n==0||n==1)  return ;
        int a=0,b=0,c=0;
        for(int i=0;i<n;i++){
            if(A[i]==0) ++a;
            else if(A[i]==1)    ++b;
            else    ++c;
        }
        for(int i=0;i<n;i++){
            if(a>0){
                --a;A[i]=0;
            }
            else if(b>0){
                --b;A[i]=1;
            }
            else if(c>0){
                --c;A[i]=2;
            }
        }
        return ;
    }
};

//one-pass solution
class Solution {
public:
    void sortColors(int A[], int n) {
        int one_index=0, two_index = n-1;
        int i=one_index;
        while(i<=two_index){
            if(A[i]==0){
                swap(A[i],A[one_index]);
                ++one_index;++i;
            }
            else if(A[i]==2){
                swap(A[i],A[two_index]);
                --two_index;
            }
            else    ++i;
        }
        return;
    }
};