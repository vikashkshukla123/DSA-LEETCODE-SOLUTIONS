class Solution {
public:
vector<int>sieve(int n){
vector<int>prime(n+1,1);
prime[0] = 0;
prime[1] = 0;
for(int p = 2; p*p <= n ; p++){
    if(prime[p] == true){
        for(int i = p*p; i<=n; i+=p)
            prime[i] = false;
        }
    }

    // prefixSum
    for(int i = 1; i<=n; i++){
        prime[i] = prime[i] + prime[i-1];
    }

return prime;
}
    int nonSpecialCount(int l, int r) {
        int sqrtl = sqrt(l);
        int sqrtr = sqrt(r);

        if((sqrtl*sqrtl) != l){
            sqrtl++;
        }
        vector<int>prime = sieve(sqrtr);
        int primes = prime[sqrtr] - prime[sqrtl - 1];
        return (r - l +1 ) - primes;
    }
};