class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.length();
        if(n == 1 && s[0] == '1') return true;
        int result = 0;
        int i = 0;
        int cnt1 = 0;
        while(i  < n){
            if(s[i] == '0'){
                i++;
                cnt1 = 0;
                continue;
            }
            int j = i;
            while(j < n && s[j] == '1'){
                j++;
                cnt1++;

            }
            i = j;


            if(cnt1 >= 1){
                result++;
            }
        }

        if(result == 1){
            return true;
        }


        return false;
    }
};