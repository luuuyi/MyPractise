/*class Solution {
private:
    int halfSearch(int A[], int begin,int end, int target){
        while(begin<=end){
            int mid = (begin+end)/2;
            if(A[mid]==target)  return mid;
            else if(A[mid]<target)  begin = mid + 1;
            else    end = mid -1;
        }
        return -1;
    }

    int rotateSearch(int A[], int begin,int end, int target){
        while(begin<end){
            if(end-begin<=1)    return begin;
            int mid = (begin+end)/2;
            if(A[mid]>=A[begin])    begin = mid;
            if(A[mid]<=A[end])  end = mid;
        }
        return begin;
    }
public:
    bool search(int A[], int n, int target) {
        if(A[n-1]>A[0]){
            if(halfSearch(A,0,n-1,target)!=-1)  return true;
            else    return false;
        }
        else if(A[n-1]==A[0]){
            if(A[0]==target)    return true;
            int begin = 0, end = n-1;
            while(A[begin]==A[0])   ++begin;
            while(A[end]==A[n-1])   --end;
            int mid = rotateSearch(A,begin,end,target);
            if(begin==end)  mid--;
            if(target>A[0]){
                if(halfSearch(A,0,mid,target)!=-1)  return true;
                else    return false;
            }
            else{
                if(halfSearch(A,mid+1,n-1,target)!=-1)  return true;
                else    return false;
            }
        }
        else{
            int mid = rotateSearch(A,0,n-1,target);
            if(target>=A[0]){
                if(halfSearch(A,0,mid,target)!=-1)  return true;
                else    return false;
            }
            else{
                if(halfSearch(A,mid+1,n-1,target)!=-1)  return true;
                else    return false;
            }
        }
    }
};*/

class Solution {
private:
    int halfSearch(int A[], int begin,int end, int target){
        while(begin<=end){
            int mid = (begin+end)/2;
            if(A[mid]==target)  return mid;
            else if(A[mid]<target)  begin = mid + 1;
            else    end = mid -1;
        }
        return -1;
    }
public:
    bool search(int A[], int n, int target) {
        if(A[n-1]>A[0]){
            if(halfSearch(A,0,n-1,target)!=-1)  return true;
            else    return false;
        }
        int begin = 0, end = n-1;
        while(begin<=end){
            int mid = (begin+end)/2;
            if(A[mid]==target)  return true;
            if(A[mid]==A[begin]&&A[mid]==A[end]){
                --end;++begin;
            }
            else if(A[mid]>=A[begin]){
                if(A[begin]<=target&&target<A[mid]) end = mid-1;
                else    begin = mid+1;
            }
            else if(A[mid]<=A[end]){
                if(A[mid]<target&&target<=A[end]) begin = mid+1;
                else    end = mid-1;
            }
        }
        return false;
    }
};