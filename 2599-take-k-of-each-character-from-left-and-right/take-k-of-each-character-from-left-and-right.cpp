class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.length();
        unordered_map<char,int>mp;
        int cnta = 0;
        int cntb = 0;
        int cntc = 0;
        for(int i = 0; i<n; i++){
            if(s[i] == 'a'){
                cnta++;
                mp['a'] = cnta;
            }else if(s[i] == 'b'){
                cntb++;
                mp['b'] = cntb;
            }else{
                cntc++;
                mp['c'] = cntc;
            }
        }

        if(cnta < k || cntb < k || cntc < k){
            return -1;
        }

        int AtmostA = cnta - k;
        int AtmostB = cntb - k;
        int AtmostC = cntc - k;


        int left = 0;
        int right = 0;
        int max_len = -1e9;

        int cntA = 0;
        int cntB = 0;
        int cntC = 0;

        while(right < n){
            if(s[right] == 'a') cntA++;
            if(s[right] == 'b') cntB++;
            if(s[right] == 'c') cntC++;


            while(left < n && (cntA > AtmostA || cntB > AtmostB || cntC > AtmostC)){
                if(s[left] == 'a') cntA--;
                if(s[left] == 'b') cntB--;
                if(s[left] == 'c') cntC--;

                left++;

            }

            if(cntA <= AtmostA && cntB <= AtmostB && cntC <= AtmostC){
                max_len = max(max_len, right - left + 1);
            }

            right++;

        }

        return (n - max_len);
    }
};