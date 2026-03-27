class Solution {
public:
 #define ll long long
 bool isVowel(char ch){
    return (ch == 'a' || ch == 'e' || ch == 'o' || ch == 'i' || ch == 'u');
 }
    long long beautifulSubstrings(string s, int k) {
        int n = s.length();
        // key {vowel - consonant} -> value -> {vowel ka count past me and number of time uska occurence}
        unordered_map<ll,unordered_map<ll,ll>>mp;
        ll ans = 0;
        ll vowel = 0;
        ll consonant = 0;
        ll diff = 0;
        mp[0][0] = 1;

        for(char &ch : s){
            if(isVowel(ch)){
                vowel++;
            }else{
                consonant++;
            }

            ll pSum = (vowel - consonant);
            for(auto &[pastVowelCount,count] : mp[pSum]){
               if((vowel % k - pastVowelCount) * (vowel % k - pastVowelCount) % k == 0){
                ans += count;
               }


            }
            mp[pSum][vowel % k]++;
        }

return ans;


        
    }
};