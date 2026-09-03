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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>nodes;
        ListNode*temp = head;
        while(temp != NULL){
            nodes.push_back(temp->val);
            temp = temp->next;
        }


        int n = nodes.size();
        vector<int>nextGreater(n,0);
        stack<int>st;
        for(int i = n-1; i >= 0; i--){
           while(!st.empty() && nodes[st.top()] <= nodes[i]){
               st.pop();
           }
           if(st.empty()){
              nextGreater[i] = 0;
              st.push(i);
              continue;
           }
           nextGreater[i] = nodes[st.top()];
           st.push(i);
           
        

        }
        return nextGreater;
        
    }
};