class Solution {
public:
    bool cycle(int node,vector<vector<int>>& graph,vector<bool>& visited,vector<bool>& inRecursion){
        visited[node] = true;
        inRecursion[node] = true;
        for(auto &nb:graph[node]){
            if(!visited[nb]){
                if(cycle(nb,graph,visited,inRecursion))
                return true;
            }
            else if(inRecursion[nb])
            return true;
        }
        inRecursion[node] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> gp(numCourses,vector<int>());
        for(auto &ele:prerequisites){
            int a = ele[0];
            int b = ele[1];
            gp[b].push_back(a);
        }
        // agar kisi bhi course ko karte samay cycle exist karti ho to app course nahi kar sake immediatly false return
        for(int i=0;i<numCourses;i++){
        vector<bool> visited(numCourses,false);
        vector<bool> inRecursion(numCourses,false);
        if(cycle(i,gp,visited,inRecursion))
        return false;
        }
        return true;
    }
};
