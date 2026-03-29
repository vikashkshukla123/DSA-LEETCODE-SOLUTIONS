class Solution {
public:
void check(int &n){
    int num = n;
    for(int i = 0; i<32; i++){
        if(num - pow(2,i) < 0){

            n = min(pow(2,i) - num, num - pow(2,i-1));
            break;

        }
    }
    return ;
}
    int minOperations(int n) {
        int ans = 0;
        while(n != 0){
            check(n);
            ans++;
        }
        

        return ans;
    }
};