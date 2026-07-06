// 2360. Longest Cycle in a Graph


class Solution {
public:
    int longestCycle(vector<int>& edges) {
        
        int n = edges.size();
        vector<vector<int>>adj(n);

        for(int i=0;i<n;i++){
            if(edges[i] != -1)
            adj[i].push_back(edges[i]);
        }

        vector<int>InDeg(n,0);

        for(int i=0; i<n; i++){
            for(int j=0; j<adj[i].size(); j++){
                InDeg[adj[i][j]]++;
            }
        }

        queue<int>q;

        for(int i=0; i<n; i++){
            if(!InDeg[i]) q.push(i);
        }

            while(!q.empty()){
                int node = q.front();
                q.pop();

                for(int j=0; j<adj[node].size(); j++){
                    InDeg[adj[node][j]]--;

                    if(InDeg[adj[node][j]] == 0) q.push(adj[node][j]);
                }
            }
        
        vector<bool>vis(n,0);
        int answ = -1;

        for(int i=0; i<n ;i++){

            if(InDeg[i] > 0 && !vis[i]){

                int count = 0;
                int curr = i;

                while(!vis[curr]){
                    vis[curr] = 1;
                    count++;
                    curr = edges[curr];
                }
                answ = max(answ,count);
            }
        }

        return answ;
    }
};
