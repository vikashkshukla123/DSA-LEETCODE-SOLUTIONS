class Solution {
public:
    int smallestNumber(int n) {
        int p = 0;
        while(true){
            int a = pow(2,p) - 1;
            if(a >= n){
                return a;
                break;
            }
            p++;

        }
        
    }
};