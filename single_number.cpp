class Solution {
public:
    void insertSort(int A[], int n){
        for (int i = 0; i<n; i++){
            int j = i - 1, tmp = A[i];
            while (j >= 0 && A[j]>tmp){
                A[j + 1] = A[j];
                --j;
            }
            A[j + 1] = tmp;
        }
    }
    void findResult(int A[], int l, int r, int &result){
        if (r>l){
            int mid = (l + r) / 2;
            if (A[mid] == A[mid - 1] || A[mid] == A[mid + 1]){
                if (A[mid] == A[mid - 1]){
                    if ((mid-l+1)&0x01)	return findResult(A, l, mid, result);
                    else	findResult(A, mid + 1, r, result);
                }
                else{
                    if ((r - mid + 1) & 0x01)	return findResult(A, mid, r, result);
                    else	findResult(A, l, mid-1, result);
                }
            }
            else{
                result = A[mid];
            }
        }
        else
            result = A[l];
    }
    int singleNumber(int A[], int n) {
        if (n == 0)    return 0;
        if (n == 1)    return A[0];
        insertSort(A, n);
        int result = 0;
        findResult(A, 0, n - 1, result);
        return result;
    }
};