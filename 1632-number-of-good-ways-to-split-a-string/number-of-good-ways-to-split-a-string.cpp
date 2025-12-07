class Solution {
public:
    int numSplits(string s) {
        int n = s.length();
        unordered_set<char>st;
        for(int i = 0; i<n; i++){
            st.insert(s[i]);
        }

        if(st.size() == 1){
            return n-1;
        }
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;

        for(int i = 0; i<n; i++){
            mp1[s[i]]++;
        }

        int ans = 0;
        for(int i = 0; i<n; i++){
            char c = s[i];
            mp1[c]--;
            if(mp1[c] == 0){
                mp1.erase(c);
            }
            mp2[c]++;


            if(mp1.size() == mp2.size()){
                ans++;
            }


        }
        return ans;
    }
};