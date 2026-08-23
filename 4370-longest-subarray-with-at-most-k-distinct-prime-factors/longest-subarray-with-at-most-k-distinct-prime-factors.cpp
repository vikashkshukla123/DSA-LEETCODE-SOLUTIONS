class Solution {
public:
vector<int> findFactor(int num, vector<int>& primes) {
    vector<int> ans;

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {

            if (primes[i]) {
                ans.push_back(i);
            }

            int other = num / i;

            if (other != i && primes[other]) {
                ans.push_back(other);
            }
        }
    }

    if (primes[num]) {
        ans.push_back(num);
    }

    return ans;
}
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = 0;
        for(int i = 0; i < n; i++){
            maxi = max(maxi,nums[i]);
        }
        vector<int>primes(maxi+1,1);
        primes[0] = 0;
        primes[1] = 0;
        for(int i = 2; i * i <= maxi; i++){
            if(primes[i] == 1){
            for(int j = i*i; j <= maxi; j+=i){
                primes[j] = 0;
                }
            }
        }
        unordered_map<int,vector<int>>mp;
        for(int i = 0; i < n; i++){
            vector<int> res = findFactor(nums[i],primes);
            mp[nums[i]] = res;
        }


        int ans = 0;
        int curr_factor = 0;
        int left = 0;
        int right = 0;
        unordered_map<int,int>mp1;
        while(right < n){
            vector<int>factors = mp[nums[right]];
            for(int i = 0; i < factors.size(); i++){
                mp1[factors[i]]++;
            }

            while(left < n && mp1.size() > k){
                vector<int>factors = mp[nums[left]];
                for(int i = 0; i < factors.size(); i++){
                    mp1[factors[i]]--;
                    if(mp1[factors[i]] == 0){
                        mp1.erase(factors[i]);
                    }
                }
                left++;
            }

            if(mp1.size() <= k){
                ans = max(ans,right - left + 1);
            }
            right++;
        }
        return ans;
    }
};