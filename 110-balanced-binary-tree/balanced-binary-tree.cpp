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

int findHeight(TreeNode*root){
    if(root == NULL){
        return 0;
    }
    return 1 + max(findHeight(root->left), findHeight(root->right));
}
bool solve(TreeNode* root){
    if(root == NULL) return true;

    int height_left = findHeight(root->left);
    int height_right = findHeight(root->right);

    if(height_left - height_right == -1 || height_left - height_right == 0 || height_left - height_right == 1){
        bool solve1 = solve(root->left);
        bool solve2 = solve(root->right);


        if(solve1 && solve2){
            return true;
        }

        
    }
    return false;
}
    bool isBalanced(TreeNode* root) {
        return solve(root);
        
    }
};