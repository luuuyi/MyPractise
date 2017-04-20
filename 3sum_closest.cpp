class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int lens = num.size();
        if(lens<3)  return 0; 
        sort(num.begin(),num.end());
        int min_diff = 0x7fffffff, min_res;
        for(int i=0;i<lens-2;i++){
            //if(num[i]>=target)  break;
            for(int j=i+1;j<lens-1;j++){
                //if(num[i]+num[j]>=target)   break;
                for(int k=j+1;k<lens;k++){
                    if(abs(num[i]+num[j]+num[k]-target)<min_diff){
                        min_res = num[i]+num[j]+num[k];
                        min_diff = abs(num[i]+num[j]+num[k]-target);
                    }
                }
            }
        }
        return min_res;
    }
};

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target)
    {
        int sum=num[0]+num[1]+num[2];
        int diff=abs(sum-target);
        sort(num.begin(),num.end());
        for(int i=0;i<num.size()-2;++i)
        {
            int  left=i+1,right=num.size()-1;
            while(left<right)
            {
                int newsum=num[i]+num[left]+num[right];
                int newdiff=abs(newsum-target);
                if(diff>newdiff)
                {
                    diff=newdiff;
                    sum=newsum;
                }
                if(newsum<target)
                    ++left;
                else
                    --right;
            }
        }
        return sum;  
    }
};