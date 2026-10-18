// 96. Unique Binary Search Trees.cpp

int solve(int start, int end, vector<vector<int>>&dp){
    if(start > end){
        return 1;
    }

    if(dp[start][end] != -1){
        return dp[start][end];
    }

    int result = 0;
    for(int i=start; i<=end; i++){

        auto left_bst = solve(start,i-1,dp);
        auto right_bst = solve(i+1,end,dp);

        result += (left_bst * right_bst);

    }
    return dp[start][end] = result;
}
class Solution {
public:
    int numTrees(int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(1,n,dp);
    }
};



// MLE:
// class Node {
//     public:
//     int val;
//     Node *left;
//     Node *right;
    
//     Node(int value){
//         val = value;
//         left = NULL;
//         right = NULL;
//     }
//   };

// vector<Node*>solve(int start, int end){
//     if(start > end){
//         return {NULL};
//     }
//     if(start == end){
//         Node*root = new Node(start);
//         return {root};
//     }

//     vector<Node*>result;
//     for(int i=start; i<=end; i++){

//         auto left_bst = solve(start,i-1);
//         auto right_bst = solve(i+1,end);

//         for(auto left : left_bst){
//             for(auto right : right_bst){

//                 Node*root = new Node(i);
//                 root->left = left;
//                 root->right = right;

//                 result.push_back(root);
//             }
//         }
//     }
//     return result;
// }
// class Solution {
// public:
//     int numTrees(int n) {
//         vector<Node*>result = solve(1,n);
//         return result.size();
//     }
// };
