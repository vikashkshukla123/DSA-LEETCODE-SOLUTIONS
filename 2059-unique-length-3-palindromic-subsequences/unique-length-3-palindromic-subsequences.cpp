class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        vector<int>firstI(26,-1);
        vector<int>lastI(26,-1);

        for(int i = 0; i<n; i++){
            int idx = s[i] - 'a';
            if(firstI[idx] == -1){
                firstI[idx] = i;

            }
        }
        for(int i = n-1; i>=0; i--){
            int idx = s[i] - 'a';
            if(lastI[idx] == -1){
                lastI[idx] = i;
            }
        }

        int ans = 0;
        for(int i = 0; i<26; i++){
            if(firstI[i] == -1 || lastI[i] == -1){
                continue;
            }else if(firstI[i] == lastI[i]){
                continue;
            }else{
                unordered_set<char>st;
                int k = firstI[i] + 1;
                int l = lastI[i] - 1;

                for(int m = k; m<=l ; m++){
                    char ch = s[m];
                    if(st.empty() || st.find(ch) == st.end()){
                        st.insert(ch);
                    }
                }
                ans += st.size();
                
            }
        }
        return ans;
    }
};