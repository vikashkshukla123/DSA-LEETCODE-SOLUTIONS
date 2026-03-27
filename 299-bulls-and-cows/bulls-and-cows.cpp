class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.length();
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;

        for(int i = 0; i<n; i++){
            mp1[secret[i]]++;
            mp2[guess[i]]++;
        }

        int bulls = 0;
        for(int i = 0; i<n; i++){
            if(secret[i] == guess[i]){
                bulls++;

                mp1[secret[i]]--;
                mp2[guess[i]]--;

                if(mp1[secret[i]] == 0) mp1.erase(secret[i]);
                if(mp2[guess[i]] == 0) mp2.erase(guess[i]);
            }
        }

        int cows = 0;

        for(auto &[num,freq] : mp1){
            if(mp2.find(num) != mp2.end()){
                cows += min(freq,mp2[num]);

            }
        }

        string ans = "";

        ans += to_string(bulls) + "A" + to_string(cows) + "B";
        return ans;
        
    }
};