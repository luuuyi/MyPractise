//method 1
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int lens = gas.size();
        if(lens == 0)   return -1;

        for(int start=0;start<lens;start++){
            bool is_cycle = false;
            int has_gas = 0;
            for(int i = start;; i++){
                has_gas += gas[i%lens];
                if(has_gas-cost[i%lens]>=0){
                    is_cycle = true;
                    has_gas -= cost[i%lens];
                }
                else{
                    is_cycle = false;
                    break;
                }
                if((i+1)%lens == start) break;
            }
            if (is_cycle)   return start;
        }

        return -1;
    }
};

//method 2
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int lens = gas.size();
        if(lens == 0)   return -1;

        int start = lens-1, end = 0;
        int sum = gas[start] - cost[start];
        while(start>end){
            if(sum>=0){
                sum += gas[end] - cost[end];
                ++end;
            }
            else{
                --start;
                sum += gas[start] - cost[start];
            }
        }
        return sum >=0 ? start: -1;
    }
};