class Solution {
public:
    long long coloredCells(int n) {
        if(n == 1){
            return 1LL;
        }
        long long ans = 1LL;
        long long to_minus = n-1;
        for(int i = 2; i <= n; i++){
            long long res = 1LL*4 * (n-to_minus);
            ans += res;
            to_minus--;
        }

return ans;
        
    }
};