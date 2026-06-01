class Solution {
public:
    bool cycle(int node,vector<vector<int>>& graph,vector<bool>& visited,vector<bool>& inRecursion){
        visited[node] = true;
        inRecursion[node] = true;
        for(auto &nb:graph[node]){
            if(!visited[node]){
                if(cycle(nb,graph,visited,inRecursion))
                return true;
            }
            else if(inRecursion[node])
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
        vector<bool> visited(numCourses,false);
        vector<bool> inRecursion(numCourses,false);
        return !cycle(0,gp,visited,inRecursion);
    }
};
