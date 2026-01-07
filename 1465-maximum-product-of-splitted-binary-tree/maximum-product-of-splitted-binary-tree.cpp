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
    long long treeSum = 0;
    long long ans = 0;
    const int mod = 1e9 + 7;
public:
long long totalSum(TreeNode*root){
    if(root == NULL){
        return 0;
    }
    return  root->val + totalSum(root->left) + totalSum(root->right);
}

long long postOrder(TreeNode*root){
    if(root == NULL){
        return 0 ;
    }

    long long leftSum = postOrder(root->left);
    long long rightSum = postOrder(root->right);

    long long subtree1 = leftSum + rightSum + root->val;
    long long subtree2 = treeSum - subtree1;


    ans = max(ans, subtree1 * subtree2);


    return subtree1;


}
    int maxProduct(TreeNode* root) {
        treeSum = totalSum(root);
        

        postOrder(root);

        return ans % mod;
     


        
    }
};