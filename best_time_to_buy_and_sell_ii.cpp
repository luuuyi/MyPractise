//solution 1
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int lens = prices.size();
        if(lens==0) return 0;
        if(lens==2) return (prices[1]-prices[0]>0)?prices[1]-prices[0]:0;
        int sum=0,last_low = prices[0], last_high = prices[0];
        for(int i =1;i<lens-1;i++){
            if(prices[i]>prices[i-1]&&prices[i]>prices[i+1]){
                last_high = prices[i];
                sum+=last_high-last_low;
            }
            if(prices[i]<prices[i-1]&&prices[i]<prices[i+1]){
                last_low = prices[i];
            }
        }
        return sum;
    }
};

//solution 2
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int lens = prices.size();
        if(lens==0) return 0;
        
        int sum = 0;
        for(int i=0;i<lens-1;i++){
            if(prices[i+1]>prices[i])   sum += prices[i+1]-prices[i];
        }
        return sum;
    }
};