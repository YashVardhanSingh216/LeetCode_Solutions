// 99. Recover Binary Search Tree

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

void inorder(TreeNode*root, vector<int>&temp){

    if(!root){
        return;
    }

    inorder(root->left,temp);
    // cout<<root->val<<" ";
    temp.push_back(root->val);
    inorder(root->right,temp);
}

void update(TreeNode*root, vector<int>&t, int &curr){

    if(!root)
    return;

    update(root->left,t,curr);
    root->val = t[curr++];
    update(root->right,t,curr);
}

class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<int>t;
        inorder(root,t);
        sort(t.begin(),t.end());

        int curr = 0;
        update(root,t,curr);
    }
};
