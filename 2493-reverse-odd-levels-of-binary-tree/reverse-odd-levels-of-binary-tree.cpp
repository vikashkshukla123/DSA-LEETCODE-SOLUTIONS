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
int level;
    TreeNode* reverseOddLevels(TreeNode* root) {
        level = -1;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            level++;
            int size = q.size();
            if(level % 2 == 0){
                for(int i = 0;i < size; i++){
                    TreeNode* node = q.front();
                    q.pop();

                    if(node->left){
                        q.push(node->left);
                    }

                    if(node->right){
                        q.push(node->right);
                    }

                }

            }else{
                vector<TreeNode*>vec;
                for(int i = 0; i < size; i++){
                    TreeNode* node = q.front();
                    q.pop();
                    vec.push_back(node);

                }

                int l = 0;
                int r = vec.size()- 1;
                while(l <= r){
                    TreeNode*node1 = vec[l];
                    TreeNode*node2 = vec[r];
                    swap(node1->val,node2->val);
                    l++;
                    r--;
                }

                for(int i = 0; i < vec.size(); i++){
                    TreeNode*node = vec[i];
                    if(node->left){
                        q.push(node->left);
                    }

                    if(node->right){
                        q.push(node->right);
                    }
                }


               


            }

        }

        return root;

        
    }
};