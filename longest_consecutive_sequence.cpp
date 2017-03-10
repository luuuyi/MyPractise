class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        int lens = num.size();
        if(lens==0) return 0;

        unordered_map<int,int> umap;
        for(int i=0;i<lens;i++){
            ++umap[num[i]];
        }
        int max = 0x80000000;
        for(int i=0;i<lens;i++){
            if(umap[num[i]]){
                int left = num[i]-1, right = num[i]+1,count=1;
                --umap[num[i]];
                while(umap[left]){
                    --umap[left];
                    --left;
                    ++count;
                }
                while(umap[right]){
                    --umap[right];
                    ++right;
                    ++count;
                }
                if(count>max)   max = count;
            }
        }
        return max;
    }
};