class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.length();
        unordered_map<char,int>mp;
        for(int i = 0; i < n; i++){
            char ch = text[i];
            if(ch == 'b' || ch == 'a' || ch == 'l' || ch == 'o' || ch == 'n'){
                mp[ch]++;
            }
        }

        if(mp.size() < 5){
            return 0;
        }
        int ans = 1e9;
        for(auto it = mp.begin(); it != mp.end(); it++){
            if(it->first == 'l' && it->second < 2){
                return 0;
            }
            if(it->first == 'o' && it->second < 2){
                return 0;
            }

            
            ans = min(ans, it->second);

        }
        int f1 = mp['l'];
        int f2 = mp['o'];

        ans = min(ans, min(f1/2,f2/2));
        return ans;
    }
};