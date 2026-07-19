class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        int n = s.length();
        string ans = "";
        int cntx = 0;
        int cnty = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == y){
                cnty++;
            }else if(s[i] == x){
                cntx++;
            }
        }

        for(int i = 0; i < cnty; i++){
            ans += y;
        }

        for(int i = 0; i < cntx; i++){
            ans += x;
        }

        for(int i = 0; i < n; i++){
            if(s[i] !=  x  && s[i] != y){
                ans += s[i];
            }
        }

        return ans;
    }
};