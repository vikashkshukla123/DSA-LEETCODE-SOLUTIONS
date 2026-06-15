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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL  || head->next == NULL) return NULL;
        ListNode*temp = head;
        int cnt = 0;
        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }

        int to_reach = cnt/2 - 1;
        ListNode*curr = head;
        while(to_reach -- ){
            curr = curr->next;
        }

        curr->next = curr->next->next;


        return head;

        
    }
};