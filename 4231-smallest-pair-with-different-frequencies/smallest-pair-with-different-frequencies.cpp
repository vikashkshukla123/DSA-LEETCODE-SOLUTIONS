class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i = 0; i<n; i++){
            mp[nums[i]]++;
        }
        

        sort(nums.begin(),nums.end());
        vector<int>ans;
        

        for(int i = 0; i<n-1; i++){
            int a = nums[i];

            for(int j = i+1; j<n; j++){
                if(nums[j] == a) continue;

                if(mp[a] != mp[nums[j]]){
                    ans.push_back(a);
                    ans.push_back(nums[j]);
                    return ans;
                }
            }
        }

        if(ans.empty()){
            ans.push_back(-1);
            ans.push_back(-1);
        }
        return ans;
    }
};