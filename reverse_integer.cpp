class Solution {
public:
    int reverse(int x) {
        bool mark = x>0?true:false;
        int tmp = abs(x), reverse_x = 0;
        while(tmp>0){
            reverse_x = reverse_x*10 + tmp%10;
            tmp /= 10;
        }
        return mark?reverse_x:-reverse_x;
    }
};