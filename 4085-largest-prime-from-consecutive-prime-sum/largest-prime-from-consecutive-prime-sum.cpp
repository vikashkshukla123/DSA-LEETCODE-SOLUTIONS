class Solution {
public:

    void precomputePrime(vector<int>& primeArray, int n){
        primeArray[0] = 0;
        primeArray[1] = 0;

        for(int i = 2; i * i <= n; i++){
            if(primeArray[i] == 1){
                for(int j = i * i; j <= n; j += i){
                    primeArray[j] = 0;
                }
            }
        }
    }

    int largestPrime(int n) {

        vector<int> primeArray(n+1,1);
        precomputePrime(primeArray,n);

        vector<int> prime;

        for(int i = 2; i <= n; i++){
            if(primeArray[i] == 1){
                prime.push_back(i);
            }
        }

        int ans = 0;
        int idx = 0;
        int sum = 0;

        while(idx < prime.size()) {
            sum += prime[idx];

            if(sum > n){
                
                break;
            }

            if(primeArray[sum]){
                ans = sum;
            }
            idx++;
        }

        return ans;
    }
};
