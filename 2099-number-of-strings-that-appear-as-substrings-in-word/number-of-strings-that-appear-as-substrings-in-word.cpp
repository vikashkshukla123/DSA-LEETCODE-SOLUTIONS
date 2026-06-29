class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n = patterns.size();
        unordered_set<string>st;

        int ans = 0;
        int m = word.length();
        for(int i = 0; i<m; i++){
            for(int j = i; j<m; j++){
                string s = word.substr(i,j-i+1);
                st.insert(s);
                
            }
        }
        for(int i = 0; i<n; i++){
            if(st.find(patterns[i]) != st.end()){
                ans ++;
            }
        }

        return ans;

        
    }
};