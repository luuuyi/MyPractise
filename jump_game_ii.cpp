//out of time
class Solution {
private:
    void jumpHelper(int A[], int cur, int n, int now, int& res){
        if(cur>=n){
            if(now<res) res = now;
            return;
        }
        for(int i=1;i<=A[cur];i++){
            jumpHelper(A,cur+i,n,now+1,res);
        }
    }
public:
    int jump(int A[], int n) {
        if(n==0)    return 0;
        int res = 0x7fffffff;
        jumpHelper(A,0,n,0,res);
        return res;
    }
};

//solution1
class Solution {
public:
    int jump(int A[], int n) {
        int cur=0;  // 每个台阶内最远去的地方
        int last=0;  // 每一步直接能跨越的最远距离
        int step=0;  //步数
        for(int i=0; i<n && cur>=i; ++i)
        {
            if(i>last)
            {
                last=cur;
                step++;
            }
            cur =max(cur, A[i]+i);
        }
         
        return step;
         
    }
};

//solution dp
//TODO