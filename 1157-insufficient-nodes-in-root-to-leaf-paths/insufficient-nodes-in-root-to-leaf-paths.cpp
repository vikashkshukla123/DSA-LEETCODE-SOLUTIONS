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
TreeNode* solve(TreeNode*root, int curr_sum, int limit){
    if(root == NULL) return NULL;
    if(root->left == NULL && root->right == NULL){
        if(curr_sum + root->val >= limit){
            return root;
        }else{
            return NULL;
        }
    }




    TreeNode* solve1 = solve(root->left, curr_sum + root->val, limit);
    TreeNode* solve2 = solve(root->right, curr_sum + root->val, limit);

    root->left = solve1;
    root->right = solve2;

    if(root->left == NULL && root->right == NULL){
        return NULL;
    }




    return root;




}
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return solve(root, 0,limit);
        
    }
};