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
string getSubTreeString(TreeNode*root, unordered_map<string,int>&mp, vector<TreeNode*>&ans){
    if(root == NULL){
        return "#";
    }

    string left = getSubTreeString(root->left, mp,ans);
    string right = getSubTreeString(root->right,mp,ans);

    string serialized = to_string(root->val) + "," + left + "," + right;
    if(mp.find(serialized) != mp.end() && mp[serialized] == 1){
        ans.push_back(root);
    }

    mp[serialized]++;
    return serialized;

}
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int>mp;
        vector<TreeNode*>ans;
        getSubTreeString(root,mp,ans);
        return ans;
        
    }
};