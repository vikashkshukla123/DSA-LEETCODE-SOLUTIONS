class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i<n; i++){
            int sum = 0;
            unordered_set<int>st;
            for(int j = i; j<n; j++){
                    sum += nums[j];
                    st.insert(nums[j]);
                

                for(auto it = st.begin(); it != st.end(); it++){
                    int ele = *it;

                    if(sum == ele){
                        ans++;
                        break;
                    }
                    continue;

                }
            }
        }
        return ans;
    }
};