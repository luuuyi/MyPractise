链接：https://www.nowcoder.com/questionTerminal/03905f7b819241398b02ee39bef3e8f1
来源：牛客网

别人家小孩的代码，引自leetcode
https://discuss.leetcode.com/topic/5934/is-it-best-solution-with-o-n-o-1
public class Solution {
    public int maxProfit(int[] prices) {
        int hold1 = Integer.MIN_VALUE, hold2 = Integer.MIN_VALUE;
        int release1 = 0, release2 = 0;
        for(int i:prices){                              // Assume we only have 0 money at first
            release2 = Math.max(release2, hold2+i);     // The maximum if we've just sold 2nd stock so far.
            hold2    = Math.max(hold2,    release1-i);  // The maximum if we've just buy  2nd stock so far.
            release1 = Math.max(release1, hold1+i);     // The maximum if we've just sold 1nd stock so far.
            hold1    = Math.max(hold1,    -i);          // The maximum if we've just buy  1st stock so far. 
        }
        return release2; ///Since release1 is initiated as 0, so release2 will always higher than release1.
    }
}

class Solution {
private:
    int calc(vector<int> &prices, int begin, int end){
        vector<int> tmp;
        int min_v = 0x7fffffff;
        for(int i=begin;i<=end;i++){
            min_v = min(prices[i],min_v);
            tmp.push_back(min_v);
        }
        int max_profit = 0;
        for(int i=0;i<tmp.size();i++){
            max_profit = max(max_profit,prices[i+begin]-tmp[i]);
        }
        return max_profit;
    }
public:
    int maxProfit(vector<int> &prices) {
        int lens = prices.size();
        int max_profit = 0;
        for(int i=0;i<lens;i++){
            max_profit = max(calc(prices,0,i) + calc(prices,i+1,lens-1),max_profit);
        }
        return max_profit;
    }
};