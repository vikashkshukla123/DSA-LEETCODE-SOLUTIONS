class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        while(a != 0 ||  b != 0 || c != 0){
            int right_a = a & 1;
            int right_b = b & 1;
            int right_c = c & 1;

            if(right_a == 0 && right_b == 0 && right_c == 1){
                ans++;
                a = a >> 1;
                b = b >> 1;
                c = c >> 1;
            }else if(right_a == 1 && right_b == 0 && right_c == 0){
                ans++;
                a = a >> 1;
                b = b >> 1;
                c = c >> 1;
            }else if(right_a == 1 && right_b == 1 && right_c == 0){
                ans += 2;
                a = a >> 1;
                b = b >> 1;
                c = c >> 1;
            }else if(right_a == 0 && right_b == 1 && right_c == 0){
                ans++;
                a = a >> 1;
                b = b >> 1;
                c = c >> 1;
            }else{
                a = a >> 1;
                b = b >> 1;
                c = c >> 1;
            }

        }
       
        return ans;
    }
};