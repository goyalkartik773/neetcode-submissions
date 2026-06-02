class Solution {
public:
    bool cycle(int node,int parent ,vector<vector<int>>& gp,vector<bool>& visited){
        visited[node] = true;
        for(auto &nb:gp[node]){
            if(!visited[nb]){
                if(cycle(nb,node,gp,visited))
                return true;
            }
            else if(nb!=parent)
            return true;
        }
        return false;
    }
    void dfs(int node,vector<bool>& visited,vector<vector<int>>& gp){
        visited[node] = true;
        for(auto &nb:gp[node]){
            if(!visited[nb]){
                dfs(nb,visited,gp);
            }
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
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
                dfs(i,visited,gp);
                count += 1;
            }
        }
        if(count>1) return false;
        vector<bool> visited1(n,false);
        return !cycle(0,-1,gp,visited1);
    }
};
