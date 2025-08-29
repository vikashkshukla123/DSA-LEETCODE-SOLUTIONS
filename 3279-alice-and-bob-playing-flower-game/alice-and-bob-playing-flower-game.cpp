class Solution {
public:
    long long flowerGame(int n, int m) {
        long long ans = 0;
        long long odd_cnt_in_n = (n+1)/2;
        long long even_cnt_in_m = m/2;
        ans += odd_cnt_in_n * even_cnt_in_m;

        long long even_cnt_in_n = n/2;
        long long odd_cnt_in_m = (m+1)/2;

        ans += even_cnt_in_n * odd_cnt_in_m;

        return ans;
        
    }
};