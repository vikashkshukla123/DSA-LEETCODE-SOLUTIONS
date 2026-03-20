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
int N;

vector<TreeNode*>solve(int start, int end){
    if(start > end){
        return {NULL};
    }

    if(start == end){
        TreeNode* temp = new TreeNode(start);
        return {temp};

    }
    vector<TreeNode*>result;

    for(int i = start; i<=end; i++){
        vector<TreeNode*>left = solve(start,i-1);
        vector<TreeNode*>right = solve(i+1,end);

        for(TreeNode* leftRoot : left){
            for(TreeNode * rightRoot : right){
                TreeNode * root = new TreeNode(i);
                root->left = leftRoot;
                root->right = rightRoot;


                result.push_back(root);
            }
        }
    }

    return result;


}
    vector<TreeNode*> generateTrees(int n) {
        N = n;
        return solve(1,n);


        
    }
};