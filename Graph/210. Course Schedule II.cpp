// 210. Course Schedule II

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        int n = prerequisites.size();
        vector<int>adj[V];
        vector<int>indeg(V,0);
        vector<bool>visited(V,0);
        vector<int>ans;

        for(int i=0; i<n; i++){
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];

            adj[u].push_back(v);
            indeg[v]++;
        }

        queue<int>q;
        for(int i=0; i<V; i++){
            if(indeg[i] == 0){
            q.push(i);
            ans.push_back(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            if(visited[node]) continue;
            visited[node] = 1;

            for(int k=0; k<adj[node].size(); k++){
                
                indeg[adj[node][k]]--;

                if(!indeg[adj[node][k]]){
                q.push(adj[node][k]);
                ans.push_back(adj[node][k]);
                }
            }
        }

        vector<int>temp;
        return (ans.size() == V) ? ans : temp;
    }
};
