// 802. Find Eventual Safe States

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();

        vector<int>outdeg(V,0);

        for(int i=0; i<V; i++){
            outdeg[i] = graph[i].size();
        }
        set<int>ans;

        for(int i=0; i<V; i++){
            // cout<<outdeg[i]<<" ";

            if(outdeg[i] == 0)
            ans.insert(i);
        }

        bool changed = true;

        while(changed){
            changed = false;

            for(int j=0; j<V; j++){
            
            if(ans.count(j))
            continue;

            bool is_ter = 1;
                for(int k=0; k<graph[j].size(); k++){

                    if(outdeg[graph[j][k]] != 0){
                    is_ter = 0;
                    break;
                    }
                }
                if(is_ter){
                    ans.insert(j);
                    outdeg[j] = 0;
                    changed = true;
                }
            }
        }
        return vector<int>(ans.begin(),ans.end());
    }
};
