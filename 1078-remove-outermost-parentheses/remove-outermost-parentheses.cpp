class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();
        int total = 0;
        int i = 0;
        int j = 0;
        int cnt = 0;
        string ans = "";
        while(i < n){
            if(s[i] == '('){
                cnt++;
            }else{
                cnt--;
            }


            if(cnt == 0){
                string res = s.substr(j + 1, i - j + 1 - 2);
                ans += res;
                j = i + 1;
            }

            
            i++;

        }
return ans;
        
        
    }
};