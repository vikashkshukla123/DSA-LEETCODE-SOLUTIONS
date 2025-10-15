class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char,int>mp;
        string s1 = "qwertyuiop";
        string s2 = "asdfghjkl";
        string s3 = "zxcvbnm";
        for(int i = 0; i<s1.length(); i++){
            mp[s1[i]] = 1;
        }
        for(int i = 0; i<s2.length(); i++){
            mp[s2[i]] = 2;
        }
        for(int i = 0; i<s3.length(); i++){
            mp[s3[i]] = 3;
        }
        vector<string>ans;
        for(int i = 0; i<words.size(); i++){
            string s = words[i];

            int row = mp[tolower(s[0])];
            int j = 1;
            while(j < s.length() && mp[tolower(s[j])] == row){
                j++;
            }
            if(j == s.length()){
                ans.push_back(s);
            }

            

            
        }
        return ans;


    }
};