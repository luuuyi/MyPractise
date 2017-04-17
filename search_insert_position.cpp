class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if(n==0)    return 0;
        if(A[0]>target) return 0;
        if(A[n-1]<target)   return n;
        for(int i=0;i<n-1;i++){
            if(target>=A[i]&&target<=A[i+1]){  
                if(target>A[i]&&target<=A[i+1])    return i+1;
                else    return i;
            }
        }
        return 0;
    }
};