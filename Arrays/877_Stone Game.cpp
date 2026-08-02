// 877. Stone Game

// bool winner(int i,int j,long long alice,long long bob,int turn,vector<int>&nums){
    
//     if(i > j) return alice >= bob;

//     if(turn == 1){
//         return winner(i+1,j,alice + nums[i] ,bob,0,nums) || winner(i,j-1,alice+nums[j],bob,0,nums);
//     }
//     else{
//         return winner(i+1,j,alice ,bob + nums[i],1,nums) || winner(i,j-1,alice,bob+nums[j],1,nums);
//     }

// }
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int  n = piles.size();
        long long alice = 0;
        long long bob = 0;

        // return winner(0,n-1,alice,bob,1,piles);
        return true;
    }
};
