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
        if(!head){
            return head;
        }
        int len = 1;
        ListNode*temp = head;
        ListNode*newh = head;
        while(temp->next != NULL){
            len++;
            temp = temp->next;
        }
        temp->next = head;
        if(k %= len){
        for(int i = 0; i<len - k; i++){
            temp = temp->next;
        }
        }
        newh = temp->next;
        temp->next = NULL;

        return newh;
         

    }
};