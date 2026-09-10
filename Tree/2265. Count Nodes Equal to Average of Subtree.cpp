// 2265. Count Nodes Equal to Average of Subtree

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

void traverse(TreeNode* root,int &sum,int &count){

    if(!root) return;

    // v.push_back({sum,count});
    sum += root->val;
    count++;

    traverse(root->left,sum,count);
    traverse(root->right,sum,count);

}

class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        
        int ans = 0;

        queue<TreeNode*>q;
        q.push(root);
        int sum = 0;
        int count = 0;

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            sum = 0;
            count = 0;

            traverse(node,sum,count);

            if(sum/count == node->val)
            ans++;

            if(node->left)
            q.push(node->left);

            if(node->right)
            q.push(node->right);

        }


        cout<<ans<<endl;
        return ans;
    }
};
