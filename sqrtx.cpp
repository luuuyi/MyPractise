class Solution {
public:
    int sqrt(int x) {
        int low=0,high=x;
        while(low<=high){
            long middle = (low+high)/2;
            long res_1 = middle*middle;
            if(x==res_1)  return middle;
            else if(x>res_1)    low = int(middle+1);
            else if(x<res_1)    high = int(middle-1);
        }
        return high;
    }
};