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
class FindElements {
public:
unordered_set<int>st;
void solve(TreeNode*root, int val, unordered_set<int>&st){
    if(!root){
        return;
    }

    st.insert(val);
    if(root->left){
        solve(root->left, 2 * val + 1,st);
    }

    if(root->right){
        solve(root->right, 2 * val + 2,st);
    }
    return;

}
    FindElements(TreeNode* root) {
        unordered_set<int>st1;
        st = st1;
        solve(root,0,st);

        
    }
    
    bool find(int target) {
        if(st.find(target) != st.end()){
            return true;
        }
        return false;
        
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */