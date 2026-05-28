class Solution {
public:
    int minOperations(int k) {
        if(k <= 1) return 0;
        int start_with = 2;
        int ans = 1e9;
        for(int startWith = 0; startWith <= k; startWith++){
            int op1 = 1 + startWith;
            int op2 = ceil((double)k/op1) - 1;

            ans = min(ans, startWith + op2);
        }
        return ans;
    }
};