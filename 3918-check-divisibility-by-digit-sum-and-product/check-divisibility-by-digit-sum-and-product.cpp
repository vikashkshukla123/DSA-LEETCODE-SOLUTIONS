class Solution {
public:
int digitSum(int n){
    int sum = 0;
    while(n != 0){
        int c = n % 10;
        sum += c;
        n = n / 10;

    }
return sum;
}

int digitMul(int n){
    int mul = 1;
    while(n != 0){
        int c = n % 10;
        mul *= c;
        n = n/10;
    }
    return mul;
}
    bool checkDivisibility(int n) {
        int a = digitSum(n);
        int b = digitMul(n);

        int divisible = a + b;
        if(n % divisible == 0){
            return true;
        }
        return false;
    }
};