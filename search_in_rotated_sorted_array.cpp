class Solution {
private:
    int halfSearch(int A[], int begin, int end, int target){
        int begin_tmp = begin, end_tmp = end;
        int res = -1;
        while(begin_tmp<=end_tmp){
            int mid = (begin_tmp+end_tmp)/2;
            if(A[mid]==target)  return mid;
            else if(A[mid]>target)  end_tmp = mid -1;
            else    begin_tmp = mid + 1;
        }
        return res;
    }

    int findMax(int A[], int n){
        int begin = 0, end = n-1;
        while(begin<end){
            if(end-begin==1)    break;
            int mid = (begin+end)/2;
            if(A[mid]>A[begin]){
                begin = mid;
            }
            else    end = mid;
        }
        return begin;
    }
public:
    int search(int A[], int n, int target) {
        if(n==0)    return 0;
        if(A[0]>A[n-1]){
            int index = findMax(A,n);
            if(target>A[0]) return halfSearch(A,0,index,target);
            else if(target==A[0])   return 0;
            else    return halfSearch(A,index+1,n-1,target);
        }
        else{
            return halfSearch(A,0,n-1,target);
        }
    }
};