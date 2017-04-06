class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int lens = strlen(s);
        if(lens==0) return 0;
        int tmp = lens-1,count = 0;
        bool flag = true,mark = true;
        while(tmp>=0){
            if((*(s+tmp)!=' ')&&flag){
                ++count;
                mark = false;
            }
            if((*(s+tmp)==' ')&&!mark){
                flag = false;
            }
            --tmp;
        }
        return count;
    }
};