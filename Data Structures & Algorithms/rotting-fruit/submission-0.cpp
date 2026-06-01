class Solution {
public:
    vector<vector<int>> dir = {{0,1},{-1,0},{1,0},{0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        auto isSafe = [&](int a,int b)->bool{
            if((a>=0 && a<n && b>=0 && b<m) && (grid[a][b]!=0))
            return true;
            return false;
        };
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                q.push({i,j});
                visited[i][j] = true;
                }
            }
        }
        int time = 0;
        while(q.size()!=0){
            int sz = q.size();
            bool flag = false;
            for(int i=0;i<sz;i++){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for(auto &d:dir){
                    int newRow = row + d[0];
                    int newCol = col + d[1];
                    if(isSafe(newRow,newCol) && !visited[newRow][newCol]){
                        grid[newRow][newCol] = 2;  // rotten kardiya iss orange ko 
                        q.push({newRow,newCol});
                        visited[newRow][newCol] = true;
                        flag = true; // indicate atleast ek fruit to rotten kiya
                    }
                }
            }
            if(flag)
            time += 1;
        }
        return time==0?-1:time;
    }
};
