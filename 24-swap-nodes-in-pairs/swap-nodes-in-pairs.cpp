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
    ListNode* swapPairs(ListNode* head) {
        vector<int>a;
        ListNode*temp = head;
        while(temp != NULL){
            a.push_back(temp->val);
            temp = temp->next;
        }
        int n = a.size();
        for(int i = 0; i<n-1; i+=2){
            swap(a[i], a[i+1]);
        }
        ListNode*dummy = new ListNode(-1);
        ListNode*dummy1 = dummy;
        for(int i = 0; i<a.size(); i++){
            ListNode*Node = new ListNode(a[i]);
            dummy->next = Node;
            dummy = Node;
        }
        return dummy1->next;
        
    }
};