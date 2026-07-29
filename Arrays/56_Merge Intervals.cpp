// 56. Merge Intervals

void mergeintervals(int index,int n,vector<vector<int>>&ans,vector<vector<int>>&merge){

    while(index < n-1){

        if(merge[index][1] >= merge[index+1][0]){
            merge[index+1] = vector<int>{merge[index][0], max(merge[index][1],merge[index+1][1])};
            index++;
        }
        else{
            ans.push_back({merge[index][0], merge[index][1]});
            index++;
        }
    }

    ans.push_back({merge[n-1][0], merge[n-1][1]});
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& merge) {
        sort(merge.begin(), merge.end());

        int n = merge.size();
        vector<vector<int>>ans;

        mergeintervals(0,n,ans,merge);

        for(int i=0; i<ans.size(); i++){
            cout<<"{"<<ans[i][0]<<","<<ans[i][1]<<"}"<<" ";
        }

        return ans;
    }
};
