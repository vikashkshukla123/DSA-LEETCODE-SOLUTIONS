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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>nodesValue;
        ListNode*temp = head;
        while(temp != NULL){
            nodesValue.push_back(temp->val);
            temp = temp->next;
        }

        vector<int>distances;
        for(int i = 1; i < nodesValue.size()-1; i++){
            if((nodesValue[i] > nodesValue[i-1] && nodesValue[i] > nodesValue[i+1]) || (nodesValue[i] < nodesValue[i-1] && nodesValue[i] < nodesValue[i+1])){
                distances.push_back(i);
            }
        }
        
        vector<int>ans;
        if(distances.size() < 2){
            return {-1,-1};
        }
        
        int mini = 1e9;
        sort(distances.begin(),distances.end());
        int maxi = distances[distances.size() - 1] - distances[0];
        for(int i  = 1; i < distances.size(); i++){
            mini = min(mini, distances[i] - distances[i-1]);
        }
return {mini,maxi};
        
    }
};