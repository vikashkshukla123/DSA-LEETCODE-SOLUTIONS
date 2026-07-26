class Solution {
public:
bool isValid(int num, int s){
    int sum = 0;
    while(num != 0){
        sum += (num % 10);
        num =  num / 10;

    }
return (sum == s);
}
    int largestInteger(int n, int s) {
        int maxi_digit = pow(10,n) - 1;
        int maxi = -1;
        for(int i = 0; i <= maxi_digit; i++){
            if(isValid(i,s)){
                maxi = max(maxi,i);
            }
        }
    return maxi;
    }
};