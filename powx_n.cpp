class Solution {
private:
    double power(double x, int n){
        if(n==0)    return 1.0;
        double tmp = power(x,n/2);
        if(n&0x01)  return tmp*tmp*x;
        else    return tmp*tmp;
    }
public:
    double pow(double x, int n) {
        if(n<0) return 1.0/power(x,-n);
        else    return power(x,n);
    }
};