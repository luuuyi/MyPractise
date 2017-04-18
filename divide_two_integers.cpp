//out of time
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
        long long  res = 0;
        long long a = abs((long long)dividend), b = abs((long long)divisor);
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        if(b==1)    return sign==-1?-a:a;
        while (a>=b){
            long long t = b, p = 1;
            while(a>=(t<<1)){
                t = t << 1;
                p = p << 1;
            }
            a -= t;
            res += p;
        }
        return sign==-1?-res:res;
    }
};