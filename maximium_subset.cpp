class Solution {
public:
    int maxSubArray(int A[], int n) {
        int max = 0x80000000, cur = 0;
        vector<int> positions(2,0);
        int i=0;
        while(i<n){
            if(cur<=0){
                positions[0] = i;
                cur = A[i];
                if(cur>max){
                    max = cur;
                    positions[1] = i;
                }
            }
            else{
                cur+= A[i];
                if(cur>max){
                    max = cur;
                    positions[1] = i;
                }
            }
            ++i;
        }
        return max;
    }
};