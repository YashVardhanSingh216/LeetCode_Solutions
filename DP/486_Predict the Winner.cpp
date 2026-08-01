// 486. Predict the Winner

bool winner(int i, int j, int player1, int player2,bool p1, vector<int>& nums){

    if(i > j) return player1>=player2;

    if(p1){
    return winner(i+1,j,player1+nums[i],player2,0,nums) || winner(i,j-1,player1+nums[j],player2,0,nums);
    }
    else{
        return winner(i+1,j,player1,player2+nums[i],1,nums) && winner(i,j-1,player1,player2+nums[j],1,nums);
    }
}
class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return 1;

        int player1 = 0;
        int player2 = 0;

        return winner(0,n-1,player1,player2,1,nums);

        
    }
};
