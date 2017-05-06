//卡特兰数
class Solution {
private:
    int getC2nn(int n){
        long long up = 1, down = 1;
        for(int i=0;i<n;i++){
            up *= 2*n - i;
            down *= n - i;
        }
        return up/down;
    }
public:
    int numTrees(int n) {
        if(n==0)    return 0;
        else{
            return getC2nn(n)/(n+1);
        }
    }
};