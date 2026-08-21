class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int n = nums.size();
        int maxi = -1e9;
        for(int i = 0; i < n; i++){
            maxi = max(maxi,nums[i]);
        }
        vector<int>primes(maxi+1,1);
        primes[0] = 0;
        primes[1] = 0;
        for(int i = 2; i * i <= maxi; i++){
            if(primes[i] == 1){
                for(int j = i * i; j <= maxi; j+=i){
                    primes[j] = 0;
                }

            }
        }

        int ans1 = 0;
        int ans2 = 0;
        for(int i = 0; i < n; i++){
            if(primes[nums[i]] == 1){
                ans1 = i;
                break;
            }
        }

        for(int i = n-1; i >= 0; i--){
            if(primes[nums[i]] == 1){
                ans2 = i;
                break;
            }
        }

        return (ans2 - ans1);
    
    }
};