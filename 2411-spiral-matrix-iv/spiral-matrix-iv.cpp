/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>result(m,vector<int>(n,-1));
        ListNode*temp = head;
        int top = 0;
        int bottom = m-1;
        int left = 0;
        int right = n-1;
        while((top <= bottom && left <= right) && temp != NULL){
            for(int col = left ; col <= right && temp != NULL; col++){
                result[top][col] = temp->val;
                temp = temp->next;
            }
            top = top + 1;

            for(int row = top; row <= bottom && temp != NULL; row++){
                result[row][right] = temp->val;
                temp = temp->next;
            }

            right = right - 1;
            
            for(int col = right ; col >= left && temp != NULL ; col--){
                result[bottom][col] = temp->val;
                temp = temp->next;
            }
            bottom = bottom - 1;
            
            for(int row = bottom ; row >= top && temp != NULL; row--){
                result[row][left] = temp->val;
                temp = temp->next;
            }
            left = left + 1;


        }
        
return result;

        
    }
};