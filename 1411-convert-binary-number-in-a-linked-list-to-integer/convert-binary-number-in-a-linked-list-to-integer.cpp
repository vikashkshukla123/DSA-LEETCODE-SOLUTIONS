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
    int getDecimalValue(ListNode* head) {
        int len = 0;
        int ans = 0;
        ListNode*temp = head;
        while(temp != NULL){
            len++;
            temp = temp->next;
        }
        ListNode*temp1 = head;
        
        while(temp1 != NULL){
            ans += temp1->val*pow(2,len-1);
            temp1 = temp1->next;
            len--;
        }
        return ans;
    }
};