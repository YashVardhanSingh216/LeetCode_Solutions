// 1385. Find the Distance Value Between Two Arrays

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n1 = arr1.size();
        int n2 = arr2.size();

        int count = 0;
        for(int i=0; i<n1; i++){
            bool check = 1;
            for(int j=0; j<n2; j++){
                if(abs(arr2[j] - arr1[i]) <= d){
                    check = 0;
                    break;
                }
            }
            if(check){
                count++;
            }
        }

        return count;
    }
};
