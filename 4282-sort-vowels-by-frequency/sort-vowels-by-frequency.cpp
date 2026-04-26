class Solution {
public:
bool isVowel(char ch){
    return (ch == 'a' || ch == 'e' || ch == 'o' || ch == 'i' || ch == 'u');
}

    string sortVowels(string s) {
        int n = s.length();
        unordered_map<char,int>mp;
        unordered_map<char,int>mp1;
        for(int i = 0; i<n; i++){
            if(isVowel(s[i])){
                mp[s[i]]++;
                if(mp1.find(s[i]) == mp1.end()){
                    mp1[s[i]] = i;
                }
            }
        }
        vector<pair<char,int>>freq;
        for(auto it = mp.begin(); it != mp.end(); it++){
            freq.push_back({it->first,it->second});
        }

        sort(freq.begin(), freq.end(), [&](auto &a, auto &b){
    if(a.second != b.second){
        return a.second > b.second;
    } else {
        return mp1[a.first] < mp1[b.first];
    }
});
        string ans = "";
        for(int i = 0; i<n; i++){
            if(isVowel(s[i])){
                for(int j = 0; j<freq.size(); j++){
                    char ch = freq[j].first;
                    int frequency = freq[j].second;

                    if(frequency > 0){
                        ans += ch;
                        freq[j].second -= 1;
                        break;
                    }
                }
                
            }else{
                ans += s[i];
            }
        }
        return ans;
        
    }
};