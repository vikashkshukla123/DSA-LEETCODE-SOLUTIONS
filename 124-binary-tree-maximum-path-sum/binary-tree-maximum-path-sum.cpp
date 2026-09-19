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
int maxSum = -1e9;
int solve(TreeNode*root){
    if(root == NULL){
        return 0;
    }
    int left = solve(root->left);
    int right = solve(root->right);

    int case1 = left + right + root->val;
    int case2 = max(left,right) + root->val;
    int case3 = root->val;


    maxSum = max({maxSum,case1,case2,case3});
    return max(case2,case3);
   


    return max(case2,case3);


}
    int maxPathSum(TreeNode* root) {
        int ans = solve(root);
        return maxSum;
        
    }
};