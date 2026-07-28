class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        vector<int>freq(26,0);
        for(int i = 0; i < n; i++){
            int idx = s[i] - 'a';
            freq[idx]++;
        }
        string ans1 = "";
        for(int i = 0; i < 26; i++){
            char ch = i + 'a';
            
            if(freq[i] > 0){
                for(int j = 0; j < floor((double)freq[i]/2) ; j++){
                    ans1 += ch;

                }
            }
        }
        string middle;

        for(int i = 0; i < 26; i++){
            char ch = i + 'a';
            if(freq[i] > 0 && freq[i] % 2 == 1){
                middle += ch;
            }
        }

        string temp = ans1;
        reverse(temp.begin(),temp.end());

        return (ans1 + middle + temp);
    }
};