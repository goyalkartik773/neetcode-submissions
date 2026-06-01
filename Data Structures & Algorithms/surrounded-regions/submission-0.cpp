class Solution {
public:
    vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
    void dfs(int row,int col,vector<vector<char>>& board,vector<vector<bool>> &flag,vector<vector<bool>> &visited){
        if(row < 0 || row >= board.size() || col <0 || col>=board[0].size())
        return ;
        auto isSafe = [&](int a,int b)->bool{
            if(a>=0 && a < board.size() && b>=0 && b < board[0].size())
            return true;
            else
            return false;
        };
        flag[row][col] = true;
        visited[row][col] = true;
        for(auto &d:dir){
            int nR = row + d[0];
            int nC = col + d[1];
            if(isSafe(nR,nC) && !visited[nR][nC] && board[nR][nC]=='O')
            dfs(nR,nC,board,flag,visited);
        }
    }
    void solve(vector<vector<char>>& board) {
        // jo bhi O border per hai wo kabhi chnage nahi ho skate means jitne bhi region mai border O ayega unhe update nahi karna 
        // will do dfs/bfs from border Os nad marked jinhe change nahi karna
        // baki sabko change kar sakte hai
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> flag(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            if(board[i][0]=='O' && !flag[i][0]){
                vector<vector<bool>> visited(n,vector<bool>(m,false));
                dfs(i,0,board,visited,flag);
            }
        }
        for(int i=0;i<n;i++){
            if(board[i][m-1]=='O' && !flag[i][m-1]){
                vector<vector<bool>> visited(n,vector<bool>(m,false));
                dfs(i,m-1,board,visited,flag);
            }
        }
        for(int j=0;j<m;j++){
            if(board[0][j]=='O' && !flag[0][j]){
                vector<vector<bool>> visited(n,vector<bool>(m,false));
                dfs(0,j,board,visited,flag);
            }
        }
        for(int j=0;j<m;j++){
            if(board[n-1][j]=='O' && !flag[n-1][j]){
                vector<vector<bool>> visited(n,vector<bool>(m,false));
                dfs(n-1,j,board,visited,flag);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!flag[i][j])
                board[i][j] = 'X';
            }
        }

    }
};
