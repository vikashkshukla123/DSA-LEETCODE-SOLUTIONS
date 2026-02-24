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
    vector<string>v;
public:
void solve(TreeNode*root, string s){
    if(!root){
        return;
    }
    s += to_string(root->val);
    
    if(!root->right && !root->left){
        v.push_back(s);
        return;
    }

    solve(root->left, s);
    solve(root->right, s);


    return;



}
    int sumRootToLeaf(TreeNode* root) {
        v.clear();
        string str = "";
        
        solve(root, str);

        int ans = 0;
        int n = v.size();
        for(int i = 0; i<n; i++){
            string s = v[i];

            int val = stoi(s,0,2);

            ans += val;
        }
        return ans;
    }
};