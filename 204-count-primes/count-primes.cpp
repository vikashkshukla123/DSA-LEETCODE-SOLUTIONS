class Solution {
public:
vector<int>sieve(int n){
    vector<int>primes(n+1,1);
    primes[0] = 0;
    primes[1] = 0;

    for(int p = 2; p*p <= n; p++){
        if(primes[p] == true){
            for(int i = p*p; i<=n; i+=p){
                primes[i] = false;
            }
        }
    }
    return primes;
}
    int countPrimes(int n) {
        if(n <= 2) return 0;
        int ans = 0;
        vector<int>prime = sieve(n);
        for(int i = 0; i<prime.size() - 1; i++){
            if(prime[i] == true){
                ans++;
            }
        }
        return ans;
    }
};