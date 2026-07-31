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
vector<int>solve(TreeNode*root){
    if(!root){
        return {INT_MAX, INT_MIN};
    }

    vector<int>left = solve(root->left);
    vector<int>right = solve(root->right);

    int maxi = max(root->val, max(left[1], right[1]));
    int mini = min(root->val, min(left[0], right[0]));

    ans = max(ans, abs(root->val - maxi));
    ans = max(ans, abs(root->val - mini));

    return {mini, maxi};
    
}
    int maxAncestorDiff(TreeNode* root) {
        vector<int>result = solve(root);
        return ans;

        
    }
};