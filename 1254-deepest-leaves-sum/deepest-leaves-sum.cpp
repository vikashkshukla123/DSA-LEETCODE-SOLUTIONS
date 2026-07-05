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
int solve(TreeNode*root, int dept){
    int level = 0;
    queue<TreeNode*>q;
    q.push(root);

    int ans = 0;
    while(!q.empty()){
       if(level == dept){
        int size = q.size();
        for(int i = 0; i < size; i++){
            TreeNode*temp = q.front();
            
            q.pop();
            ans += temp->val;
        }

        return ans;
       }else{
        int size = q.size();
          for(int i = 0; i < size; i++){
            TreeNode*temp = q.front();
            q.pop();

            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
          }

          level++;
       }
         
    }
    return ans;

}
int maxDept(TreeNode*root){
    if(root == NULL){
        return 0;
    }

    int leftMax = 0;
    if(root->left){
        leftMax = 1 + maxDept(root->left);
    }

    int rightMax = 0;
    if(root->right){
        rightMax = 1 + maxDept(root->right);
    }


    return max(leftMax, rightMax);
}
    int deepestLeavesSum(TreeNode* root) {
        int dept = maxDept(root);
        return solve(root,dept);


        
    }
};