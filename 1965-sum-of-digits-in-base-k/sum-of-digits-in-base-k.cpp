class Solution {
public:

    int sumBase(int n, int k) {
        int sum = 0;
        while(n != 0){
            int val = n % k;
            sum += val;
            n = n / k;
        }

        return sum;
        
        
    }
};