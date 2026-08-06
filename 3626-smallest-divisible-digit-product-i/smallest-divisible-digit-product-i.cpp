class Solution {
public:
int solve(int num){
    int product = 1;
    while(num != 0){
        product *= (num % 10);
        num = num / 10;
    }
    return product;
}
    int smallestNumber(int n, int t) {
        int num = n;
        int ans = 0;
        while(true){
           int digit_mul = solve(num);
           if(digit_mul % t == 0){
              ans =  num;
              break;
           }

           num++;
            
        }
        return ans;
    }
};