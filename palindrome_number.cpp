class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int x_abs = abs(x), tmp = x_abs;
        int palindrome = 0;
        while(tmp){
            int tmp_v = tmp % 10;
            tmp /=10;
            palindrome = palindrome*10 + tmp_v;
        }
        if(palindrome == x_abs)  return true;
        else    return false;
    }
};