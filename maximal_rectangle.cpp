class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int height = matrix.size();
        if(height==0)   return 0;
        int width = matrix[height-1].size();
        int res = 0;
        for(int i = 0;i<height;i++){
            vector<int> ret(width,0);
            for(int j = 0;j<width;j++){
                int i_tmp = i;
                while(i_tmp>=0&&matrix[i_tmp][j]=='1'){
                    ++ret[j];--i_tmp;
                }
            }
            res = max(res,largestRectArea(ret));
        }
        return res;
    }

    int largestRectArea(vector<int> ret){
        ret.push_back(-1);
        int lens = ret.size();
        int i=0;
        stack<int> stk;
        int max_area = 0;
        while(i<lens){
            if(stk.empty()||ret[i]>=ret[stk.top()]){
                stk.push(i);++i;
            }
            else{
                int top_index = stk.top();
                stk.pop();
                int area = ret[top_index]*(stk.empty()?i:i-stk.top()-1);
                if(area>max_area)   max_area = area;
            }
        }
        return max_area;
    }
};