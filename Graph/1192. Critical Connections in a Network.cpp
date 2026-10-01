// 1192. Critical Connections in a Network


void DFS(int node, int parent, vector<vector<int>>&adj, vector<int>&dt, vector<int>&low,vector<bool>&visited, vector<vector<int>>&bridges, int count){

    dt[node] = low[node] = count;
    visited[node] = 1;

    for(int j=0; j<adj[node].size(); j++){

        int neigh = adj[node][j];

        if(neigh == parent) continue;

        else if(visited[neigh]){
            low[node] = min(low[node], low[neigh]);
        }

        else{
            count++;
            DFS(neigh ,node,adj,dt,low,visited,bridges,count);
            low[node] = min(low[node], low[neigh]);

            // check bridge
            if(low[neigh] > dt[node]){
                vector<int>temp;
                temp.push_back(node);
                temp.push_back(neigh);
                bridges.push_back(temp);
            }
        }
    }

}
class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<vector<int>>adj(n);

        for(int i=0; i<connections.size(); i++){

            int u = connections[i][0];
            int v = connections[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<vector<int>>bridges;
        vector<int>dt(n); // discovery time
        vector<int>low(n); // low

        vector<bool>visited(n,0);

        int count = 0;
        DFS(0,-1,adj,dt,low,visited,bridges,count);

        return bridges;

    }
};
