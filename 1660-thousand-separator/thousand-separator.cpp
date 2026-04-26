class Solution {
public:
    string thousandSeparator(int n) {
        string to_find = "";
        int cnt = 0;
        if(n == 0) return "0";
        while(n != 0){
            if(cnt == 3 && n != 0){
                to_find += '.';
                cnt = 0;
            }else{
                cnt++;
                int val = n % 10;
                to_find += (val + '0');
                n = n / 10;
            }

        }
        reverse(to_find.begin(),to_find.end());
        return to_find;
    }
};