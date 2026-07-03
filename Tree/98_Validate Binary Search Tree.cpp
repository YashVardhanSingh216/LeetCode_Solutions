// 98_Validate Binary Search Tree

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

void inord(TreeNode* root,vector<int>&check){

    if(!root) return;
    
    inord(root->left,check);
    check.push_back(root->val);
    inord(root->right,check);


}
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        
        vector<int>check;
        inord(root,check);

        for(int i=0; i<check.size()-1; i++){
            if(check[i+1] <= check[i]) return false;
        }

        return true;
    }
};
