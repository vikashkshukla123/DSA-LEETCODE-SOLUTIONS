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
 vector<int>sorted;

TreeNode* function(int left, int right){
    if(left > right){
        return NULL;
    }
   


    int mid = left + (right - left)/2;
    TreeNode * node = new TreeNode(sorted[mid]);

    TreeNode* left_side = function(left, mid - 1);
    TreeNode * right_side = function(mid + 1, right);



    node->left = left_side;
    node->right = right_side;
  

  return node;
    
}
void solve(TreeNode* root){
    if(root == NULL){
        return;
    }
    solve(root->left);
    sorted.push_back(root->val);
    solve(root->right);
}
    TreeNode* balanceBST(TreeNode* root) {
        solve(root);
        int n = sorted.size();

        return function(0, n-1);
    }
};