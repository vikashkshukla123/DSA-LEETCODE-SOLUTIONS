class Solution {
public:
    string modifyString(string s) {
        int n = s.length();
        int i = 0;
        while(i < n){
            if(s[i] == '?' && i == 0){
                for(char ch = 'a'; ch <= 'z'; ch++){
                    if(s[i+1] != ch){
                        s[i] = ch;
                        break;
                    }
                }
            }else if(s[i] == '?' && i == n-1){
                for(char ch = 'a'; ch <= 'z'; ch++){
                    if(s[i-1] != ch){
                        s[i] = ch;
                        break;
                    }
                }

            }else if(s[i] == '?' && i >= 1 && i <= n-2){
                for(char ch = 'a'; ch <= 'z'; ch++){
                    if(s[i-1] != ch && s[i+1] != ch){
                        s[i] = ch;
                        break;
                    }
                }
            }
            i++;

        }
        return s;
    }
};