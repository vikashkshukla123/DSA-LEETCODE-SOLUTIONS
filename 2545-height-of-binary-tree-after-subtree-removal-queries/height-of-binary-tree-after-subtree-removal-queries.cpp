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
vector<int>height;
vector<int>level;
int calculateHeight(TreeNode*root){
    if(root == NULL){
        return 0;
    }

    return height[root->val] = 1 + max(calculateHeight(root->left),calculateHeight(root->right));
    
}
    vector<int>treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int>ans;
        height.resize(1e5 + 1,0);
        level.resize(1e5+1,0);
        calculateHeight(root);
        queue<pair<TreeNode*,int>>q;
        unordered_map<int,vector<int>>mp;
        q.push({root,0});
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            int lev = it.second;
            level[node->val] = lev;
            mp[lev].push_back(node->val);


            if(node->left){
                q.push({node->left,lev+1});
            }

            if(node->right){
                q.push({node->right,lev+1});
            }

            }
        }

        int m = queries.size();
        for(int i = 0; i < m; i++){
            int deleteNode = queries[i];
            int lev = level[deleteNode];
            vector<int>&morenodes = mp[lev];
            int maxHeight = 0;
            for(int j = 0; j < morenodes.size(); j++){
                if(deleteNode == morenodes[j]){
                    continue;
                }
                maxHeight = max(maxHeight,height[morenodes[j]]);
            }
            

          ans.push_back(lev + maxHeight - 1);

        }

        
return ans;

    }
};