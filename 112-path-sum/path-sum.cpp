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
bool solve(TreeNode*root, int curr){
    if(root == NULL) return false;
     if(root->left == NULL && root->right == NULL && curr == root->val) return true;
    if(solve(root->left, curr - root->val) == true) return true;
    if(solve(root->right,curr - root->val) == true) return true;

    return false;
}
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root,targetSum);
        
    }
};