class Solution {
private:
    bool isValid(vector<vector<char> > &board, int x, int y, int types){
        switch(types){
            case 1:{
                map<char,int> mp;
                for(int i=x;i<9;i++){
                    if(board[y][i]>='0'&&board[y][i]<='9'&&mp.find(board[y][i])!=mp.end()){
                        return false;
                    }
                    else if(board[y][i]>='0'&&board[y][i]<='9') mp[board[y][i]] = 1;
                }
                return true;
            }
            case 2:{
                map<char,int> mp;
                for(int i=y;i<9;i++){
                    if(board[i][x]>='0'&&board[i][x]<='9'&&mp.find(board[i][x])!=mp.end()){
                        return false;
                    }
                    else if(board[i][x]>='0'&&board[i][x]<='9') mp[board[i][x]] = 1;
                }
                return true;
            }
            case 3:{
                map<char,int> mp;
                for(int i=y;i<=y+2;i++){
                    for(int j=x;j<=x+2;j++){
                        if(board[i][j]>='0'&&board[i][j]<='9'&&mp.find(board[i][j])!=mp.end()){
                            return false;
                        }
                        else if(board[i][j]>='0'&&board[i][j]<='9') mp[board[i][j]] = 1;
                    }
                }
                return true;
            }
            default:{
                return true;
            }
        }
    }
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int x=0,y=0;
        for(int i=0;i<9;i++){
            if(!isValid(board,x+i,y,2))  return false;
            if(!isValid(board,x,y+i,1))  return false;
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(!isValid(board,x+i*3,y+j*3,3))  return false;
            }
        }
        return true;
    }
};