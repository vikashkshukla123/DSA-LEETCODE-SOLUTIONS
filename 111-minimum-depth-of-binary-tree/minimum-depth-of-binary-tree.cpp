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
int minLen = 1e9;
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,1});
        while(!q.empty()){
            auto it = q.front();
            q.pop();

            TreeNode* node = it.first;
            int dept = it.second;

            if(node->left == NULL && node->right == NULL){
                minLen = min(minLen, dept);
                continue;

            }


            if(node->left){
                q.push({node->left, dept + 1});
            }

            if(node->right){
                q.push({node->right, dept + 1});
            }







        }
        return minLen;
    }
};