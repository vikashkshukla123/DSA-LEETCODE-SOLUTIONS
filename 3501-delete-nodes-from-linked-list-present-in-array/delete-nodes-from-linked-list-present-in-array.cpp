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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>st;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            st.insert(nums[i]);
        }
        vector<int>a;
        ListNode*temp = head;
        while(temp != NULL){
            if(st.find(temp->val) == st.end()){
                a.push_back(temp->val);
                temp = temp->next;
            }else{
                temp = temp->next;
            }

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