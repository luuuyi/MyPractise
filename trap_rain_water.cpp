class Solution {
public:
    int trap(int A[], int n) {
        int max_index = -1,max=0;
        for(int i=0;i<n;i++){
            if(A[i]>max){    
                max = A[i];
                max_index = i;
            }
        }
        if(max_index == -1) return 0;
        int sum=0,left=0,right=0;
        for(int i=0;i<=max_index;i++){
            if(A[i]<left)   sum+=left-A[i];
            else    left = A[i];
        }
        for(int i=n-1;i>=max_index;i--){
            if(A[i]<right)   sum+=right-A[i];
            else    right = A[i];
        }
        return sum;
    }
};