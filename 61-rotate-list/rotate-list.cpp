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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        if(k == 0) return head;
        ListNode*temp = head;
        int len = 0;
        while(temp != NULL){
            len++;
            temp = temp->next;
        }

        if(k % len  == 0) return head;
        int newK = k % len;
        ListNode*head1 = head;
        ListNode*head2 = head;
        for(int i = 0; i < len - newK - 1; i++){
            head2 = head2->next;
        }

        ListNode*head3 = head2->next;
        ListNode*to_return = head2->next;

        for(int i = len - newK + 1; i < len; i++){
            head3 = head3->next;

        }

        head3->next = head1;
        head2->next = NULL;

        return to_return;

    

        
    }
};