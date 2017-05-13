class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        int lens = num.size();
        if(lens<3)  return vector<vector<int>>();
        sort(num.begin(), num.end());
        set<vector<int>> ret;
        for(int i=0;i<lens-2;i++){
            int first = num[i];
            if(first>0) break;
            else{
                int left = i+1, right = lens-1;
                while(left<right){
                    int tmp = first+num[left]+num[right];
                    if(tmp==0){
                        ret.insert(vector<int>({first,num[left],num[right]}));
                        --right;++left;
                    }
                    else if(tmp>0)  --right;
                    else    ++left;
                }
            }
        }
        return vector<vector<int>>(ret.begin(), ret.end());
    }
};