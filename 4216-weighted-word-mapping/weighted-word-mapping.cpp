class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n = words.size();
        unordered_map<char,int>mp;
        unordered_map<int,char>mp1;
        char ch = 'a';
        for(int i = 0; i<weights.size(); i++){
            mp[ch] = weights[i];
            ch++;

        }

        int cnt = 25;
        char ch1 = 'a';
        for(int i = 0; i<26; i++){
            mp1[cnt] = ch1;
            ch1++;
            cnt--;
        }




        string ans = "";
        for(int i = 0; i<n; i++){
            string word = words[i];

            int m = word.length();
            int sum = 0;
            for(int i = 0; i<m; i++){
                sum += mp[word[i]];


            }


            sum = sum % 26;

            ans += mp1[sum];

        }

        return ans;
        
    }
};