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
    vector<vector<int>>ans;
    void solve(TreeNode*root, int sum, vector<int> path,int &targetSum){
        if(!root) return; 
        sum += root->val;
        path.push_back(root->val);
        if(root->left == NULL && root->right == NULL){
            if(sum == targetSum){
            ans.push_back(path);
            }
            return;
        }
        solve(root->left,sum,path,targetSum);
        solve(root->right,sum,path,targetSum);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        vector<int>path;
        solve(root,sum,path,targetSum);

        return ans;
    }
};