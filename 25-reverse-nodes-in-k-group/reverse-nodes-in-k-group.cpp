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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int>a;
        ListNode*temp = head;
        int cnt = 0;
        while(temp != NULL){
            a.push_back(temp->val);
            temp = temp->next;
            cnt++;

        }
        // for(int i = 0; i<=a.size() - k; i++){
        //     int j = i + k-1;


        // while(i <= j){
        //     swap(a[i],a[j]);
        //     i++;
        //     j--;
        // } 
        // }

        for (int i = 0; i + k <= a.size(); i += k) {
            int left = i;
            int right = i + k - 1;

            while (left < right) {
                swap(a[left], a[right]);
                left++;
                right--;
            }
        }

    ListNode* head1 = new ListNode(a[0]);
    ListNode* current = head1;

    for (int i = 1; i < a.size(); i++) {
        current->next = new ListNode(a[i]);
        current = current->next;
    }

   

 return head1;





    }
};