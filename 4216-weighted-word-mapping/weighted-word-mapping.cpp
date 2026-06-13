class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        unordered_map<char,int>mp;
        unordered_map<int,char>mp1;
        int idx = 0;
        int cnt = 0;
        for(char ch = 'a'; ch <= 'z'; ch++){
            mp[ch] = weights[idx];
            idx++;
        }
        char ch = 'a';
        for(int num = 25; num >= 0; num--){
            mp1[num] = ch;
            ch++;

        }

        string ans = "";
        for(string &s : words){
            int weight = 0;
            for(int j = 0; j < s.length(); j++){
                weight += mp[s[j]];
            }

            weight = (weight) % 26;

            ans += mp1[weight];
        }
return ans;

    }
};