class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        unordered_set<int>st;
        st.insert(nums[0] - k);
        int prev_k = -k;
        for(int i = 1; i<n; i++){
            int num = nums[i];
            if(num == nums[i-1]){
            for(int i = prev_k + 1; i<=k; i++){
                if(st.find(num + i) == st.end()){
                    st.insert(num + i);
                    prev_k = i;
                    break;
                }
                continue;
            }
            }else{
                for(int i = -k; i<=k; i++){
                if(st.find(num + i) == st.end()){
                    st.insert(num + i);
                    prev_k = i;
                    break;
                }
                continue;
            }

            }
        }
        return st.size();
    }
};