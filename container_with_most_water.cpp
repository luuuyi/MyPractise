//solution 1
class Solution {
public:
    int maxArea(vector<int> &height) {
        int size = height.size();
        if(size<2)  return 0;
        int max_h = 0, index = 0;
        for(int i=0;i<size;i++){
            if(max_h<height[i]){
                max_h = height[i];
                index = i;
            }
        }
        int left = 0, right = 0, max_v = 0,sum = 0;
        for(int i=0;i<=index;i++){
            if(height[i]>left){
                left = height[i];
                max_v = max(max_v,sum);
                sum = 0;
            }
            else    sum += left - height[i];
        }
        for(int i = size-1;i>=index;i--){
            if(height[i]>right){
                right = height[i];
                max_v = max(max_v,sum);
                sum = 0;
            }
            else    sum += right - height[i];
        }
        return max_v;
    }
};

class Solution {
public:
    int maxArea(vector<int> &height) {
        int size = height.size();
        if(size<2)  return 0;
        int max_v = 0;
        for(int l=0,r = size-1;l!=r;){
            max_v = max((r-l)*(height[l]<height[r]?height[l]:height[r]),max_v);
            height[l]<height[r]?l++:r--;
        }
        return max_v;
    }
};