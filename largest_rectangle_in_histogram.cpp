class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int lens = height.size(),i=0,max=0x80000000;
        if(lens==0) return 0;
        height.push_back(-1);
        stack<int> stk;
        while(i<=lens){
            if(stk.empty()||height[stk.top()]<=height[i]){
                stk.push(i);
                ++i;
            }
            else{
                int tp = stk.top();stk.pop();
                int area = height[tp]*(stk.empty()?i:i-stk.top()-1);
                if(area>max)    max = area;
            }
        }
        return max;
    }
};