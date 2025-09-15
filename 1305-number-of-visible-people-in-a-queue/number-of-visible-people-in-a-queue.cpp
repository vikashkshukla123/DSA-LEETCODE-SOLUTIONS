class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int>ans(n,0);
        stack<pair<int,int>>st;
        for(int i = 0; i<n; i++){
            int val = heights[i];
            while(!st.empty() && st.top().first < val){
                int idx = st.top().second;
                ans[idx]++;
                st.pop();
            }
            if(!st.empty()){
                ans[st.top().second]++;
            }
            st.push({val,i});

        }
        return ans;
    }
};