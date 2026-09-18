// 739. Daily Temperatures

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {

        int n  = temp.size();

        // temp , index
        stack<pair<int,int>>st;
        vector<int>ans;

        for(int i=n-1; i>=0; i--){

            if(st.empty()){
                st.push({temp[i], i});
                ans.push_back(0);
                continue;
            }

            if(temp[i] < st.top().first){
                ans.push_back(st.top().second - i);
                st.push({temp[i], i});
            }

            else{

                while(!st.empty() && temp[i] >= st.top().first){
                    st.pop();
                }

                if(st.empty())
                ans.push_back(0);

                else{
                    int index = st.top().second;
                    ans.push_back(index - i);
                }
                
                st.push({temp[i], i});
            }
        }

        reverse(ans.begin(),ans.end());

        return ans;

    }
};
