class Solution {
    bool isVowel(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'); 
    }
public:
    int maxFreqSum(string s) {
        unordered_map<char,int>vowel;
        unordered_map<char,int>conso;
        int n = s.length();
        for(int i = 0; i<n; i++){
            if(isVowel(s[i])){
            vowel[s[i]]++;
            }else{
                conso[s[i]]++;
            }
        }
        int max_vowel = 0;
        for(auto it1: vowel){
            max_vowel = max(max_vowel, it1.second);
        }
        int max_conso = 0;
        for(auto it2 : conso){
            max_conso = max(max_conso, it2.second);
        }
        return max_vowel + max_conso;
    }
};