class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st;
        unordered_map<int,int>mp;
        sort(nums.begin(),nums.end());
        int maxi = nums[n-1];
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }

        long long sum = 0;
        for(int i = 0; i < n; i++){
            long long val = nums[i];
            long long cnt_multiple = 0;
            if(st.find(val) == st.end()){
                st.insert(val);
                cnt_multiple += mp[val];
                for(int j = val * 2 ; j <= maxi; j += val){
                    if(st.find(j) == st.end() && mp.find(j) != mp.end()){
                        cnt_multiple += mp[j];
                        st.insert(j);
                    }
                }

                sum += (1LL * cnt_multiple * val);
                
            }
            
        }
return sum;


    }
};