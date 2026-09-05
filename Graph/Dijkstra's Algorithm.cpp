// Dijkstra's Algorithm (GFG)

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        // vector<vector<int>>adj[V];
        
        // for(int i=0; i<edges.size(); i++){
            
        //     int u = edges[i][0];
        //     int v = edges[i][1];
        //     int weight = edges[i][2];
            
        //     adj[u].push_back({v,weight});
        //     adj[v].push_back({u,weight});
        // }
        
        // vector<int>dist(V,INT_MAX);
        // vector<bool>explored(V,0);
        // dist[src] = 0;
        
        // int count = V;
        
        // while(count--){
            
        //     int node = -1;
        //     int value = INT_MAX;
            
        //     for(int k=0; k<V; k++){
                
        //         if(!explored[k] && dist[k] < value){
        //             node = k;
        //             value = dist[k];
        //         }
        //     }
        //     explored[node] = 1;
            
        //     //Relax the edges
            
        //     for(int i=0; i<adj[node].size(); i++){
                
        //         int neigh = adj[node][i][0];
        //         int weight = adj[node][i][1];
                
        //         if(!explored[neigh] && dist[node]+weight < dist[neigh])
        //         dist[neigh] = dist[node]+weight;
        //     }
        // }
        
        // return dist;
        
        vector<pair<int,int>>adj[V];

        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];

            adj[v].push_back({u,weight});
            adj[u].push_back({v,weight});
        }

        vector<int>dist(V,INT_MAX);
        dist[src] = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>,
        greater<pair<int,int>>>pq;
        pq.push({0,src});

        while(!pq.empty()){

            int distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(distance > dist[node]) continue;

            for(int k=0; k<adj[node].size(); k++){

                int neigh = adj[node][k].first;
                int weight = adj[node][k].second;

                if(distance + weight < dist[neigh]){
                dist[neigh] = distance + weight;
                pq.push({dist[neigh], neigh});
                    
                }
            }
        }
        
        return dist;
    }
};
