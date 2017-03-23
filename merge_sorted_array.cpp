class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int total = m+n;
        while(m&&n){
            if(A[m-1]>=B[n-1]){
                A[total-1] = A[m-1];
                --m;
            }
            else{
                A[total-1] = B[n-1];
                --n;
            }
            --total;
        }
        while(n){
            A[total-1] = B[n-1];
            --n;--total;
        }
        while(m){
            A[total-1] = A[m-1];
            --m;--total;
        }
    }
};