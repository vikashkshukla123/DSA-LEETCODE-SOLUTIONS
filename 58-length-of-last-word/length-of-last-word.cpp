class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        if(n==1) return 1;
        int cnt = 0;
        int i = n-1;

        while(i > 0){
            while(s[i] == ' '){
                i--;
            }
            if(i == 0 && s[i] != ' ') return 1;
            while(s[i] != ' '){
                cnt++;
                i--;
                if(i == 0 && s[i] != ' '){cnt++;
                break;
                }
            }
            break;
            
        }
        return cnt;
        
    }
};