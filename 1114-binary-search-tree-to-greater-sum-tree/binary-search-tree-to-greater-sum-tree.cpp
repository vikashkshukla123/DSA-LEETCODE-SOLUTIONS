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
    void inorder(TreeNode*root, vector<int>&node){
        if(root == NULL) return;
        inorder(root->left, node);
        node.push_back(root->val);
        inorder(root->right,node);
    }

    void change(TreeNode*root,vector<int>&node){

    if (!root) return;

    int value = 0;
    for (int i = 0; i < node.size(); i++) {
        if (node[i] >= root->val) { 
            value += node[i];
        }
    }
    root->val = value;

    change(root->left, node);
    change(root->right, node);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        vector<int>node;
        inorder(root,node);

        change(root,node);
        return root;


        
    }
};