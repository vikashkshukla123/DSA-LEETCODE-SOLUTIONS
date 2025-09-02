class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();
        int cnt_1 = 0;
        for(int i = 0; i<n; i++){
            if(s[i] == '1') cnt_1++;
        }
        
        vector<pair<char,int>>store;
        int i = 0;
        int j = 0;
        while(i < n){
            int cnt = 0;
            int current = s[i];
            
            while(j<n && s[j] == current){
                cnt++;
                j++;
            }
            store.push_back({s[i], cnt});
            i = j;
        }

        int m = store.size();
        int maxi = 0;
        for(int i = 1; i<m-1; i++){
            int ans = 0;
            if(store[i].first == '1' && store[i-1].first == '0' && store[i+1].first == '0'){
                ans = store[i-1].second + store[i+1].second;
                maxi = max(maxi, ans);

            }
        }
        return cnt_1 + maxi;
    }
};