class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> res(2,-1);
        if(n==0)    return res;
        int begin=0,end=n-1;
        while(begin<=end){
            int mid = (begin+end)/2;
            if(A[mid]==target){
                int left = mid-1,right=mid+1;
                while(left>=0&&A[left]==target){
                    left--;
                }
                left++;
                while(right<n&&A[right]==target){
                    right++;
                }
                right--;
                res.assign({left,right});
                break;
            }
            else if(A[mid]>target)  end = mid -1;
            else    begin = mid + 1;
        }
        return res;
    }
};