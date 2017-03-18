class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if(m==0&&n==0)  return 0;
        if((m+n)&0x01)  return findResult(A,0,m-1,B,0,n-1,(m+n)/2);
        else    return (findResult(A,0,m-1,B,0,n-1,(n+m-1)/2)+findResult(A,0,m-1,B,0,n-1,(n+m)/2))/2.0;
    }
    double findResult(int A[],int a_s, int a_e,int B[],int b_s,int b_e,int k){
        int middle = (k+1)/2;
        if(A[middle])
    }
};

//Solution2
class Solution {
    public:
        int find_kth(int A[], int m, int B[], int n,int k){
        //假设m总是<=n
        if(m>n)
            return find_kth(B,n,A,m,k);
        if(m==0)
            return B[k-1];
        if(k==1) 
            return min(A[0],B[0]);
        //将k分为两部分
        int ia=min(m,k/2);
        int ib=k-ia;        
        if(A[ia-1]<B[ib-1])            
            return find_kth(A+ia,m-ia,B,n,k-ia);
        else if(A[ia-1]>B[ib-1])           
            return find_kth(A,m,B+ib,n-ib,k-ib);
        else
            return A[ia-1];
        }      
        double findMedianSortedArrays(int A[], int m, int B[], int n) {  
            int total=m+n;    
            if(total&1)          
                return find_kth(A,m,B,n,total/2+1);  
            else          
                return(find_kth(A,m,B,n,total/2)+find_kth(A,m,B,n,total/2+1))/2.0;    
        }
};