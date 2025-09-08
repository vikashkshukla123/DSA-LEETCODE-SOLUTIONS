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
    int max(int a, int b){
        if(a < b) return b;
        return a;
    }
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int ans = -1e9;
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        while(!q.empty()){
            long long size = q.size();
            long long min_val = q.front().second;
            long long left;
            long long right;
            for(int i = 0; i<size; i++){
                long long curr_id = q.front().second - min_val;
                TreeNode*node = q.front().first;
                q.pop();
                if(i == 0) left = curr_id;
                if(i == size - 1) right = curr_id;
                if(node->left) q.push({node->left, curr_id*2+1});
                if(node->right) q.push({node->right, curr_id*2+2});

            
            }
            ans = max(ans,right-left+1);

        }
        
        return ans;
    }
};