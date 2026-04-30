class Solution {
public:
    long long maxGCDScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>twoDivisorCount(n,0);
        for(int i = 0; i<n; i++){
            int val = nums[i];
            int cnt = 0;
            while(val % 2 == 0){
                cnt++;
                val = val / 2;
            }
            twoDivisorCount[i] = cnt;
        }

        long long maxGCD = 0LL;
        for(int i = 0; i<n; i++){
            int currentGcd = 0LL;
            int minTwoDivisor = 1e9;
            int minTwoDivisorCnt = 0;
            for(int j = i; j < n; j++){
                currentGcd = gcd(currentGcd,nums[j]);
                if(minTwoDivisor > twoDivisorCount[j]){
                    minTwoDivisor = twoDivisorCount[j];
                    minTwoDivisorCnt = 0;
                }
                if(twoDivisorCount[j] == minTwoDivisor){
                    minTwoDivisorCnt++;
                }

                int length = (j - i + 1);
                if(minTwoDivisorCnt <= k){
                    maxGCD = max(maxGCD , 2LL * length * currentGcd);
                }else{
                    maxGCD = max(maxGCD , 1LL * length * currentGcd);

                }
            }
        }
        return maxGCD;
        
    }
};