//solution 1
class Solution {
public:
    void solve(vector<vector<char>> &board) {
        int h = board.size();
        if(h==0)    return;
        int w = board[h-1].size();
        vector<vector<bool>> flag;
        for(int i=0;i<h;i++){
            vector<bool> tmp(w,false);
            flag.push_back(tmp);
        }

        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(board[i][j]=='O')
                    if(isSurrounded(board,w,h,j,i,flag)) board[i][j]='X';
            }
        }
    }

    bool isSurrounded(vector<vector<char>> &board, int w, int h,int x, int y, vector<vector<bool>> &flag){
        if(!((x>=0&&x<w)&&(y>=0&&y<h)))    return false;
        if(board[y][x]=='X')    return true;
        bool ret = true;
        if(board[y][x]=='O'&&(!flag[y][x])){
            flag[y][x] = true;
            ret = isSurrounded(board,w,h,x,y-1,flag)&&isSurrounded(board,w,h,x,y+1,flag)&&isSurrounded(board,w,h,x-1,y,flag)&&isSurrounded(board,w,h,x+1,y,flag);
            flag[y][x] = false;
        }
        return ret;
    }
};
//solution 2
class Solution {
public:
    void isSurrounded(vector<vector<char>> &board, int w, int h, int y, int x){
        if (!((x >= 0 && x<w) && (y >= 0 && y<h)))    return;
        if (board[y][x] == 'X')    return;
        //bool ret = true;
        if (board[y][x] == 'O'){
            board[y][x] = '*';
            //flag[y][x] = true;
            isSurrounded(board, w, h, y - 1,x);
            isSurrounded(board, w, h, y + 1,x);
            isSurrounded(board, w, h, y,x - 1);
            isSurrounded(board, w, h, y,x + 1);
            //flag[y][x] = false;
        }
        return;
    }
    void solve(vector<vector<char>> &board) {
        int h = board.size();
        if (h == 0)    return;
        int w = board[h - 1].size();
        vector<vector<bool>> flag;
        for (int i = 0; i<h; i++){
            vector<bool> tmp(w, false);
            flag.push_back(tmp);
        }

        for (int i = 0; i<h; i++){
            if (board[i][0] == 'O')    isSurrounded(board, w, h, i, 0);
        }
        for (int i = 1; i<w; i++){
            if (board[h - 1][i] == 'O')    isSurrounded(board, w, h, h - 1, i);
        }
        for (int i = h - 2; i >= 0; i--){
            if (board[i][w - 1] == 'O')    isSurrounded(board, w, h, i, w - 1);
        }
        for (int i = w - 2; i >= 0; i--){
            if (board[0][i] == 'O')    isSurrounded(board, w, h, 0, i);
        }
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (board[i][j] == 'O')    board[i][j] = 'X';
                if (board[i][j] == '*')    board[i][j] = 'O';
            }
        }
    }
};