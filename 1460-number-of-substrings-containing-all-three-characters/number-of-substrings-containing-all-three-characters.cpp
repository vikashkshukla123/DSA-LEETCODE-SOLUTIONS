class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        vector<int>character(3,0);
        int left = 0;
        int right = 0;
        int ans = 0;
        while(right < n){
            int idx = s[right] - 'a';
            character[idx]++;


           while(left < n && character[0] >= 1 && character[1] >= 1 && character[2] >= 1){
              ans += (s.length() - right);
               int idx = s[left] - 'a';
               character[idx]--;
               left++;

            
               }

            
            

            right++;





           
        }
        return ans;
    }
};