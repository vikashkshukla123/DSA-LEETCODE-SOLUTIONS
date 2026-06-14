class Solution {
public:
int calc(int n){
    int square = 0;
    int sumDigit = 0;
    while(n != 0){
        int val = n % 10;
        sumDigit += val;
        square += (val * val);

        n = n / 10;
    }

    return (square - sumDigit);
}
    bool checkGoodInteger(int n) {
        int solve = calc(n);
        if(solve >= 50){
            return true;
        }
        return false;
        
    }
};