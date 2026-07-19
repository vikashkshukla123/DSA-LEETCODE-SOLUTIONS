class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if(n == 1){
            return (1LL * s);
        }
        long long result = 1LL * s;
        long long ans1 = 1LL* ((long long)n/2 * m);
        result += ans1;

        long long ans2 = 1LL* (n/2 - 1);
        result -= ans2;


        return result;


        
    }
};