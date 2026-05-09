class Solution {
public:
    int findComplement(int num) {
        string s = "";
        while(num != 0){
            int rem = num % 2;
            s += rem + '0';
            num = num / 2;
        }
        reverse(s.begin(),s.end());
        int n = s.length();
        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                s[i] = '0';
            }else{
                s[i] = '1';
            }
        }

        int ans = 0;
        int p = 0;
        for(int i = n-1; i >= 0; i--){
            int bit = s[i] - '0';
            ans += bit * pow(2,p);
            p++;
        }
        return ans;
    }
};