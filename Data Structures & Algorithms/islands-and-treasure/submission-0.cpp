class Solution {
public:
    vector<vector<int>> dir = {{0,1},{-1,0},{0,-1},{1,0}};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        auto isSafe = [&](int a,int b)->bool{
            if((a>=0 && a<n && b>=0 && b<m ) && (grid[a][b]!=-1))
            return true;
            return false;
        };
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                    visited[i][j] = true;
                }
            }
        }
        while(q.size()!=0){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for(auto &d:dir){
                    int newRow = row + d[0];
                    int newCol = col + d[1];
                    if(isSafe(newRow,newCol) && !visited[newRow][newCol]){
                        grid[newRow][newCol] = 1 + grid[row][col];
                        q.push({newRow,newCol});
                        visited[newRow][newCol] = true;
                    }
                }
            }
        }
    }
};
