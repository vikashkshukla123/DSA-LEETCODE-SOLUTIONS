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
int solve(vector<int>&ele, unordered_map<int,int>&mp){
    int n = ele.size();
    vector<int>sorted = ele;
    sort(sorted.begin(),sorted.end());
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int fake_val = ele[i];
        int actual_val = sorted[i];

        if(fake_val == actual_val){
            continue;
        }
        cnt++;
        int actual_val_idx = mp[actual_val];
        swap(ele[i],ele[actual_val_idx]);
        mp[actual_val] = i;
        mp[fake_val] = actual_val_idx;

    }
    return cnt;
}

    int minimumOperations(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            unordered_map<int,int>mp;
            vector<int>ele;
            for(int i = 0; i < size; i++){
                TreeNode *node = q.front();
                q.pop();
                

                ele.push_back(node->val);
                mp[node->val] = i;


                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }

            int min_op = solve(ele,mp);
            ans += min_op;
        }
return ans;
        
    }
};