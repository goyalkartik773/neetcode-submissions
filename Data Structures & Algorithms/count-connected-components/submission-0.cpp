class Solution {
public:
    void dfs(int node,vector<vector<int>>& gp,vector<bool>& visited){
        visited[node] = true;
        for(auto &nb:gp[node]){
            if(!visited[nb]){
                dfs(nb,gp,visited);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> gp(n,vector<int>());
        for(auto &ele:edges){
            int a = ele[0];
            int b = ele[1];
            gp[a].push_back(b);
            gp[b].push_back(a);
        }
        int count = 0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,gp,visited);
                count+=1;
            }
        }
        return count;
    }
};
