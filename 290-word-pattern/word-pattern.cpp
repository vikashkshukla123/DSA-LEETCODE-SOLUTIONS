class Solution {
public:
    bool wordPattern(string pattern, string s) {
    int n = pattern.length();
    stringstream ss(s);
    string word;
    vector<string> words;

    while (ss >> word) {   // automatically skips extra spaces
        words.push_back(word);
    }

    if(n != words.size()){
        return false;
    }
    unordered_map<char,string>mp1;
    unordered_map<string,char>mp2;


    for(int i = 0; i<n; i++){
        char ch1 = pattern[i];
        string word1 = words[i];


        if(mp1.find(ch1) != mp1.end() && mp1[ch1] != word1 || mp2.find(word1) != mp2.end() && mp2[word1] != ch1){
            return false;
        }
        mp1[ch1] = word1;
        mp2[word1] = ch1;
        
    }

return true;
        
    }
};