
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int MAX = 100005;
        int n = nums.size();

        vector<int> allPrimes(MAX + 1, 1);
        allPrimes[0] = 0;
        allPrimes[1] = 0;

        for(int i = 2; i * i <= MAX; i++){
            if(allPrimes[i] == 0) continue;
            for(int j = i * i; j <= MAX; j += i){
                allPrimes[j] = 0;
            }
        }

        int ans = 0;

        for(int i = 0; i < n; i++){
            if(i % 2 == 0){
                if(allPrimes[nums[i]] == 1) continue;

                for(int j = nums[i] + 1; j <= MAX; j++){
                    if(allPrimes[j] == 1){
                        ans += j - nums[i];
                        break;
                    }
                }
            } else {
                if(allPrimes[nums[i]] == 0) continue;

                for(int j = nums[i] + 1; j <= MAX; j++){
                    if(allPrimes[j] == 0){
                        ans += j - nums[i];
                        break;
                    }
                }
            }
        }

        return ans;
    }
};