class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int lens = prices.size();
        if(lens==0) return 0;
        int max_n = 0x80000000, min_n = 0x7fffffff;
        for(int i=0;i<lens;i++){
            min_n = min(min_n,prices[i]);
            max_n = max(max_n,prices[i]-min_n);
        }
        return max_n;
    }
};