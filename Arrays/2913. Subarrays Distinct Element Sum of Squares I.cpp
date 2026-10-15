// 2913. Subarrays Distinct Element Sum of Squares I

class Solution {
public:
    int sumCounts(vector<int>& num) {

        int n = num.size();

        int sum = 0;

        for(int i=0; i<n; i++){
            set<int>temp;
            for(int j=i; j<n; j++){
                temp.insert(num[j]);
                sum += temp.size()*temp.size();
            }
        }

        return sum;
        
    }
};
