class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        int lens = words.size();
        vector<string> vecs;
        for(int i=0;i<lens;i++){
            int tmp_lens = words[i].size();
            vecs.push_back(words[i]);
            for(int j=i+1;j<lens;j++){
                int j_lens = words[i].size();
                if(tmp_lens+j_lens<L-(j-i)){
                    tmp_lens += j_lens;
                    vecs.push_back()
                }
            }
        }
    }
};