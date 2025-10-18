class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            vector<int>freq(26,0);
        for (int j = i; j < n; j++) {
            freq[s[j] - 'a']++;
            int minimum = 1e9;
            int maximum = -1e9;
            
            for(int i = 0; i<freq.size(); i++){
                if(freq[i] > 0){
                minimum = min(minimum, freq[i]);
                maximum = max(maximum, freq[i]);
            }
            }

            if(minimum == maximum){
                ans = max(ans, j - i + 1);
            }


            

        }
    }
    return ans;
        
    }
};