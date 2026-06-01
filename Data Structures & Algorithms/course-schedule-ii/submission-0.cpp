class Solution {
public:
    bool cycle(int node,vector<vector<int>>& gp,vector<bool>& visited,vector<bool>& inRecursion){
        visited[node] =  true;
        inRecursion[node] = true;
        for(auto &nb:gp[node]){
            if(!visited[nb]){
                if(cycle(nb,gp,visited,inRecursion))
                return true;
            }
            else if(inRecursion[nb])
            return true;
        }
        inRecursion[node] = false;
        return false;
    }
    void dfs(int node,vector<vector<int>>& gp,vector<bool>& visited,stack<int>& st){
        visited[node] = true;
        for(auto &nb:gp[node]){
            if(!visited[nb]){
                dfs(nb,gp,visited,st);
            }
        }
        st.push(node);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> gp(numCourses,vector<int>());
        for(auto &ele:prerequisites){
            int a = ele[0];
            int b = ele[1];
            gp[b].push_back(a);
        }
        bool flag = true;
        vector<bool> visited(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
            vector<bool> inRecursion(numCourses,false);
            if(cycle(i,gp,visited,inRecursion)){
                flag = false;
                break;
            }
            }
        }
        vector<int> result;
        if(flag){
            vector<bool> vis(numCourses,false);
            stack<int> st;
            for(int i=0;i<numCourses;i++){
                if(!vis[i]){
                    dfs(i,gp,vis,st);
                }
            }
            while(st.size()!=0){
                result.push_back(st.top());
                st.pop();
            }
        }
        return result;
    }
};
