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
    int pairSum(ListNode* head) {
        ListNode*temp = head;
        vector<int>ans;
        while(temp != NULL){
            ans.push_back(temp->val);
            temp = temp->next;
        }

        int maxi = -1e9;
        int left = 0;
        int right = ans.size() - 1;
        while(left < right){
            int sum = ans[left] + ans[right];
            maxi = max(maxi,sum);
            left++;
            right--;
        }

        return maxi;
    }
};