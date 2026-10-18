// 95. Unique Binary Search Trees II

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

vector<TreeNode*> solve(int start, int end){

    if(start > end){
        return {NULL};
    }
    if(start == end){
        TreeNode*root = new TreeNode(start);
        return {root};
    }
    vector<TreeNode*>result;
    for(int i=start; i<=end; i++){

        vector<TreeNode*>left_bst = solve(start,i-1);
        vector<TreeNode*>right_bst = solve(i+1,end);

        for(auto left : left_bst){
            for(auto right : right_bst){

                TreeNode*root = new TreeNode(i);
                root->left = left;
                root->right = right;

                result.push_back(root);
            }
        }
        
    }
    return result;
}
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        
        return solve(1,n);
    }
};
