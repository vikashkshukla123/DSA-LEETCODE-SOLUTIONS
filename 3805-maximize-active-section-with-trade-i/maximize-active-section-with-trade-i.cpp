class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();
        vector<pair<char,int>>vec;
        int cnt1 = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                cnt1++;
            }
        }
        int i = 0;
        while(i < n){
            char ch = s[i];
            int j = i;
            int cnt = 0;
            while(j < n && s[j] == ch){
                cnt++;
                j++;
                
            }
            i = j;
            vec.push_back({ch, cnt});
        }

        int ans = 0;
        for(int i = 1; i < vec.size()-1; i++){
            if(vec[i].first == '1' && vec[i+1].first == '0' && vec[i-1].first == '0'){
                ans = max(ans, vec[i-1].second + vec[i+1].second);
            }

        }

       return(ans + cnt1);
    }
};