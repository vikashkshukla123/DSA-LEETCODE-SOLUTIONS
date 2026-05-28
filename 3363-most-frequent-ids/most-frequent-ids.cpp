class Solution {
public:
typedef long long ll;
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        int n = nums.size();
        unordered_map<ll,ll>mp;
        priority_queue<pair<ll,ll>>pq;
        vector<ll>ans;
        for(int i = 0; i < n; i++){
            int value = nums[i];
            int frequency = freq[i];

            if(mp.find(value) != mp.end()){
                long long  old_frequency = mp[value];
                long long  new_frequency = old_frequency + frequency;

                mp[value] = new_frequency;
                pq.push({new_frequency,value});
            }else{
                mp[value] = frequency;
                pq.push({frequency, value});
            }

            while(!pq.empty() && (pq.top().first != mp[pq.top().second])){
                pq.pop();
            }

            if(pq.empty()){
                ans.push_back(1ll * 0);
            }else{
                ans.push_back(1ll * pq.top().first);
            }

            


        }


        return ans;
    }
};