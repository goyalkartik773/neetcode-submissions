class Solution {
public:
    vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& height) {
        int n = height.size();
        int m = height[0].size();
        auto isSafe = [&](int a,int b)->bool{
            if(a>=0 && a<n && b>=0 && b<m) return true;
            else
            return false;
        };
        // true mark jis jis cell sai pani pacific ocean mai askata hai
        vector<vector<bool>> pacificVisited(n,vector<bool>(m,false));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            q.push({i,0});
            pacificVisited[i][0] = true;
        }
        for(int j=0;j<m;j++){
            q.push({0,j});
            pacificVisited[0][j]= true;
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
                    if(isSafe(newRow,newCol) && !pacificVisited[newRow][newCol] && height[newRow][newCol] >= height[row][col]){
                        pacificVisited[newRow][newCol] = true;
                        q.push({newRow,newCol});
                    }
                }
            }
        }
        //q.clear();
        vector<vector<bool>> atlanticVisited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            q.push({i,m-1});
            atlanticVisited[i][m-1] = true;
        }
        for(int j=0;j<m;j++){
            q.push({n-1,j});
            atlanticVisited[n-1][j] = true;
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
                    if(isSafe(newRow,newCol) && !atlanticVisited[newRow][newCol] && height[newRow][newCol] >= height[row][col]){
                        atlanticVisited[newRow][newCol] = true;
                        q.push({newRow,newCol});
                    }
                }
            }
        }
        vector<vector<int>> result;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(atlanticVisited[i][j]==true && pacificVisited[i][j]==true)
                result.push_back({i,j});
            }
        }
        return result;
    }
};
