class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        for(int i=0;i<n;){
            if(A[i]==i+1){   
                ++i;
            }
            else if(A[i]>=1&&A[i]<=n&&A[A[i]-1] != A[i]){
                int tmp = A[A[i]-1];
                A[A[i]-1] = A[i];
                A[i] = tmp;
                //swap(A+i,A+A[i]-1);
            }
            else    ++i;
        }
        int i =0;
        for(;i<n;i++){
            if(A[i]!=i+1) return i+1;
        }
        return i+1;
    }
};