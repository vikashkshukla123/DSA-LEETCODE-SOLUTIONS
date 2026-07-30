class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        unordered_map<char,int>mp;
        vector<pair<int,char>>vec;
        for(int i = 0; i < n; i++){
            mp[word[i]]++;
        }

        for(auto it = mp.begin(); it != mp.end(); it++){
            char ch = it->first;
            int freq = it->second;

            vec.push_back({freq,ch});
        }

        sort(vec.rbegin(),vec.rend());
        int ans = 0;
        int multiplier = 1;
        int cnt = 0;
        for(int i = 0; i < vec.size(); i++){
            cnt++;
            if(cnt > 8 * multiplier){
                multiplier++;
            }
            ans += (vec[i].first * multiplier);
        }
        
return ans;

    }
};