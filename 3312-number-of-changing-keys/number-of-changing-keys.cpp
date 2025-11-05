class Solution {
public:
    int countKeyChanges(string s) {
        int n = s.length();
        for(int i = 0; i<n; i++){
            s[i] = tolower(s[i]);
        }
        
        int cnt = 0;
        char prev = s[0];
        for(int i = 1; i<n; i++){
            if(s[i] != prev){
                cnt++;
                prev = s[i];
            }

        }
        return cnt;
        
    }
};