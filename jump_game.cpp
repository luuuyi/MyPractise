class Solution {
public:
    bool canJump(int A[], int n) {
        int end = n-1;
        if(end <=0) return true;
        int now = 0;
        while(now<end){
            if(A[now]==0)   return false;
            now += A[now];
        }
        return true;
    }
};