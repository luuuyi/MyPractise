class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if(n==0)    return 0;
        int j=0;
        for(int i=0;i<n;i++){
            if(A[i]!=elem)  A[j++] = A[i];
        }
        return j;
    }
};