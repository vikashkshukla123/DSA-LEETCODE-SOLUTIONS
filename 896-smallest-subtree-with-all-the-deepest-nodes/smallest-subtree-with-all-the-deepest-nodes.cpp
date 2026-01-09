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
    int maxDept = 0;
public:

TreeNode* lca(TreeNode*root,int &maxDept,unordered_map<TreeNode*,int>&mp){
    if(!root){
        return nullptr;
    }

    if(mp.find(root) != mp.end() && mp[root] == maxDept){
        return root;
    }

    TreeNode*left = lca(root->left,maxDept,mp);
    TreeNode*right = lca(root->right,maxDept, mp);


    if(left != nullptr && right != nullptr){
        return root;
    }

    else if(left != nullptr && right == nullptr){
        return left;
    }

    return right;


    
}

void dept(TreeNode*root, unordered_map<TreeNode*,int>&mp, int depth){
    if(!root){
        return;
    }

    mp[root] = depth;
    maxDept = max(maxDept, depth);
    dept(root->left,mp, depth + 1);
    dept(root->right, mp, depth + 1);

    return;

    
}
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        unordered_map<TreeNode*,int>mp;
        dept(root, mp,0);




        return lca(root,maxDept,mp);
        
    }
};