class Solution {
public:
int mod = 1e9 + 7;
    int countOrders(int n) {
        if(n == 1) return 1;
        int previous = 1;
        long long possibility = 1;
        long long  ans = 0;

        for(int i = 2; i <= n; i++){
            long long spaces = (2LL*(i-1) + 1) % mod;
            long long  possible = (spaces * (spaces + 1)/2) % mod;
            ans = (possible * possibility) % mod;
            possibility = ans % mod;

        }

        return ans;

    }
};