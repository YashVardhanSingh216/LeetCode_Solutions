// 207. Course Schedule

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        int n = prerequisites.size();
        vector<int>adj[V];
        vector<int>indeg(V,0);
        vector<bool>visited(V,0);

        for(int i=0; i<n; i++){
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];

            adj[u].push_back(v);
            indeg[v]++;
        }

        queue<int>q;
        for(int i=0; i<V; i++){
            if(indeg[i] == 0)
            q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            if(visited[node]) continue;
            visited[node] = 1;

            for(int k=0; k<adj[node].size(); k++){
                
                indeg[adj[node][k]]--;

                if(!indeg[adj[node][k]])
                q.push(adj[node][k]);
            }
        }

        bool ans = true;
        for(int i=0; i<V; i++){
            if(visited[i] == 0){
            ans = false;
            break;
            }
        }

        return ans;
    }
};
