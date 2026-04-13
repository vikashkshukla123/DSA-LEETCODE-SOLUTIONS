class Solution {
public:
    int maxRepOpt1(string text) {
        int n = text.length();
        vector<int> character(26, 0);

        for(char c : text){
            character[c - 'a']++;
        }

        int ans = 0;

        for(char ch = 'a'; ch <= 'z'; ch++){
            int left = 0, right = 0;
            int diff = 0;

            while(right < n){
                if(text[right] != ch){
                    diff++;
                }

                while(diff > 1){
                    if(text[left] != ch){
                        diff--;
                    }
                    left++;
                }

                ans = max(ans, min(right - left + 1, character[ch - 'a']));
                right++;
            }
        }

        return ans;
    }
};