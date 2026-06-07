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
TreeNode* solve(TreeNode* rootNode, unordered_map<int,vector<vector<int>>>&parentToChild){
    if(parentToChild.find(rootNode->val) == parentToChild.end()){
        return rootNode;
    }


   vector<vector<int>>&child = parentToChild[rootNode->val];
   bool left = true;
   bool right = true;

   if(child.size() == 1 && child[0][1] == 1){
       right = false;
   }
   if(child.size() == 1 && child[0][1] == 0){
    left = false;
   }

   int leftNode = -1;
   int rightNode = -1;

   for(int i = 0; i < child.size(); i++){
    if(child[i][1] == 1){
        leftNode = child[i][0];
    }else{
        rightNode = child[i][0];
    }
   }


   if(left == true && right == false){
    TreeNode * leftnode = new TreeNode(leftNode);
    rootNode->left = solve(leftnode, parentToChild);
   }else if(left == false && right == true){
    TreeNode * rightnode = new TreeNode(rightNode);
    rootNode->right = solve(rightnode,parentToChild);
   }else{
    TreeNode * leftnode = new TreeNode(leftNode);
    TreeNode * rightnode = new TreeNode(rightNode);

    rootNode->left = solve(leftnode, parentToChild);
    rootNode->right = solve(rightnode, parentToChild);

   }

return rootNode;

   


    
}
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n = descriptions.size();
        unordered_map<int,vector<vector<int>>>parentToChild;
        unordered_map<int,int>childToParent;
        int root = -1;
        for(int i = 0; i < n; i++){
            parentToChild[descriptions[i][0]].push_back({descriptions[i][1],descriptions[i][2]});
            childToParent[descriptions[i][1]] = descriptions[i][0];


        }

        for(int i = 0; i < n; i++){
            if(childToParent.find(descriptions[i][0]) == childToParent.end()){
                root = descriptions[i][0];
                break;
            }
        }


        TreeNode * rootNode = new TreeNode(root);
        return solve(rootNode,parentToChild);
        




        
    }
};