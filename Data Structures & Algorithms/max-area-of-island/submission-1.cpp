class Solution {
public:
    int ones = 0;
    vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
    void dfs(int row,int col,vector<vector<bool>> &visited,vector<vector<int>> &grid){
        visited[row][col] = true;
        ones+=1;
        auto isSafe = [&](int a,int b)->bool{
            if(a>=0 && a < grid.size() && b>=0 && b < grid[0].size())
            return true;
            return false;
        };
        for(auto &d:dir){
            int newRow = row + d[0];
            int newCol = col + d[1];
            if(isSafe(newRow,newCol) && !visited[newRow][newCol] && grid[newRow][newCol]==1){
                dfs(newRow,newCol,visited,grid);
            } 
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int result = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]==1){
                    ones = 0;
                    dfs(i,j,visited,grid);
                    result = max(result,ones);
                }
            }
        }
        return result;
    }
};
