class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        string t = s + s;

        string t1 = "";
        string t2 = "";
        for(int i = 0; i<2*n; i++){
            if(i % 2 == 0){
                t1 += '0';
                t2 += '1';
            }else{
                t1 += '1';
                t2 += '0';
            }
        
        }

        int left = 0;
        int right = 0;

        int total_length = 2 * n;

        int ans = 1e9;
        int flip1 = 0;
        int flip2 = 0;

        while(right < 2*n){
            if(t1[right] != t[right]) flip1++;
            if(t2[right] != t[right]) flip2++;


            if(right - left + 1 > n){
                if(t1[left] != t[left]) flip1--;
                if(t2[left] != t[left]) flip2--;
                left++;
            }


            if(right - left + 1 == n){
                ans = min(ans, min(flip1,flip2));
            }

            right++;
        }
        return ans;
    }
};