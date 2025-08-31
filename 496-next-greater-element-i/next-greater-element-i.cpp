class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        int n = nums1.size();
        int m = nums2.size();

        vector<int>next_greater(m+1);

        stack<int>st;
        for(int i = m-1; i>=0; i--){
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }
            if(st.empty()){
                next_greater[i] = -1;
            }else{
                next_greater[i] = st.top();
                
            }
            st.push(nums2[i]);
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(nums1[i] == nums2[j]){
                    ans.push_back(next_greater[j]);
                    break;
                }
            }
        }
        return ans;

        
    }
};