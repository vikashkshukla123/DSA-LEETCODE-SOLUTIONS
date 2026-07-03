class Solution {
public:

    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>primes(n+1,1);
        primes[0] = 0;
        primes[1] = 0;

        for(int i = 2; i * i < n; i++){
            if(primes[i] == 1){
                for(int j = i*i; j < n; j += i){
                    primes[j] = 0;
                }
            }
        }

        long long sumA = 0;
        long long sumB = 0;
        for(int i = 0; i < n; i++){
            if(primes[i]){
                sumA += nums[i];
            }else {
                sumB += nums[i];
            }
        }
return llabs(sumA - sumB);
    }
};