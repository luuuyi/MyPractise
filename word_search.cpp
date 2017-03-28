class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        int height = board.size();
        int width = board[0].size();
        vector<vector<bool>> flag(height,vector<bool>(width,false));
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                if(dfs(board,j,i,flag,word,0)) return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char> >& board,int x, int y,vector<vector<bool>>& flag, string& word, int index){
        if(index==word.size())  return true;
        if(x<0||x>=board[0].size()||y<0||y>=board.size())   return false;
        if(flag[y][x])  return false;
        if(board[y][x]!=word[index])    return false;

        flag[y][x] = true;
        bool res =  dfs(board,x,y-1,flag,word,index+1)||
                dfs(board,x,y+1,flag,word,index+1)||
                dfs(board,x-1,y,flag,word,index+1)||
                dfs(board,x+1,y,flag,word,index+1);
        flag[y][x] = false;
        return res;

    }
};