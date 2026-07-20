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
int ans = 0;
int solve(TreeNode*root){
    if(!root){
        return -1e9;
    }


    int left = solve(root->left);
    int right = solve(root->right);

    if(max(left, right) <= root->val){
        ans++;
    }
    return max(left,max(right,root->val));
}
    int countDominantNodes(TreeNode* root) {
        solve(root);
        return ans;

        
    }
};