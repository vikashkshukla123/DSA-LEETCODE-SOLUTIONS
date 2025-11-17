class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        int n = paths.size();
        unordered_set<string>st;
        unordered_map<string,string>mp;
        for(int i = 0; i<n; i++){
            string from = paths[i][0];
            string to = paths[i][1];
            st.insert(from);
            st.insert(to);
            mp[from] = to;
        }
        string ans = "";
        for(auto it = st.begin(); it != st.end(); it++){
            if(mp.find(*it) == mp.end()){
                ans = *it;
            }
        }
        return ans;
    }
};