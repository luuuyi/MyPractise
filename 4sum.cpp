class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        int lens = num.size();
        if(lens<4)  return vector<vector<int>>();
        sort(num.begin(),num.end());
        set<vector<int>> ret;
        for(int i=0;i<lens-3;i++){
            for(int j=i+1;j<lens-2;j++){
                int first = num[i] + num[j];
                int left = j+1, right = lens-1;
                while(left<right){
                    int tmp = first+num[left]+num[right];
                    if(tmp==target){
                        ret.insert(vector<int>({num[i],num[j],num[left],num[right]}));
                        ++left;--right;
                    }
                    else if(tmp>target) --right;
                    else    ++left;
                }
            }
        }
        return vector<vector<int>>(ret.begin(),ret.end());
    }
};

//hash solution
//TODO