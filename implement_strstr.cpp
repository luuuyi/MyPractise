class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        string s = haystack, p = needle;
        int pos = s.find(p);
        if(pos!=string::npos)   return haystack+pos;
        else    return NULL;
    }
};