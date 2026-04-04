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
int min(int a, int b){
    if(a < b) return a;
    return b;
}
void reverse(int left, int right, vector<int>&res){
    while(left <= right){
        swap(res[left],res[right]);
        left++;
        right--;
    }

    return;
}
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        vector<int>res;
        ListNode*temp = head;
        while(temp != NULL){
            res.push_back(temp->val);
            temp = temp->next;
        }

        int size = 1;
        int i = 0;

        while(i < res.size()){
            int start = i;
            int end = min(i + size - 1, res.size() - 1);
            int actualSize = end - start + 1;

            if(actualSize % 2 == 0){
                reverse(start,end,res);
                // even size ;
            }
            i = end + 1;
            size++;


        }
        ListNode*temp1 = new ListNode(-1);
        ListNode*head1 = temp1;
        for(int i = 0; i<res.size(); i++){
            ListNode* nayaNode = new ListNode(res[i]);
            temp1->next = nayaNode;
            temp1 = temp1->next;
        }
        return head1->next;
    }
};