class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st;
        for(int i = 0; i < n; i++){
           st.insert(nums[i]);
        }

        int distinct = st.size();
        int left = 0;
        int right = 0;

        unordered_map<int,int>mp;
        int ans = 0;
        while(right < n){
            mp[nums[right]]++;

            while(left < n && mp.size() == distinct){
                ans += (nums.size() - right);
                mp[nums[left]]--;

                if(mp[nums[left]] == 0){
                    mp.erase(nums[left]);
                }
                left++;
            }

            right++;

        }
        
        return ans;

    


    }
};