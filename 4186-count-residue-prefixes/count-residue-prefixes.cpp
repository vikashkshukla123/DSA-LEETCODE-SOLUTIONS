class Solution {
public:
    int residuePrefixes(string s) {
        int n = s.length();
        unordered_set<char>st;
        int prefixlen = 0;
        int ans = 0;
        for(int i = 0; i<n; i++){
            prefixlen++;
            st.insert(s[i]);

            int cond = prefixlen % 3;
            int setSize = st.size();

            if(cond == setSize){
                ans++;
            } 
        }
        return ans;
    }
};