// 103. Binary Tree Zigzag Level Order Traversal

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
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root){
            return {};
        }
        stack<TreeNode*>s1;
        stack<TreeNode*>s2;
        vector<vector<int>>ans;
        s1.push(root);

        while(!s1.empty() || !s2.empty()){

            if(!s1.empty()){
                vector<int>store;
                while(!s1.empty()){
                    TreeNode*temp1 = s1.top();
                    s1.pop();

                    store.push_back(temp1->val);

                    if(temp1->left){
                        s2.push(temp1->left);
                    }
                    if(temp1->right){
                        s2.push(temp1->right);
                    }
                }
                ans.push_back(store);

            }
            else{
                vector<int>store;
                while(!s2.empty()){
                    TreeNode*temp2 = s2.top();
                    s2.pop();

                    store.push_back(temp2->val);

                    if(temp2->right){
                        s1.push(temp2->right);
                    }
                    if(temp2->left){
                        s1.push(temp2->left);
                    }
                }
                ans.push_back(store);

            }
        }
        return ans;

    }
};
