class Solution {
public:
bool isVowel(char ch){
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch =='u') return true;
    return false;
}
    bool isValid(string word) {
        int n = word.length();
        if(n < 3) return false;

        bool Vowel = false;
        bool Consonant = false;

        for(int i = 0; i<n; i++){
            char ch = word[i];
            if(isalpha(ch)){
                ch = tolower(ch);
                if(isVowel(ch)){
                    Vowel = true;
                }
                else{
                    Consonant = true;
                }
            }
            else if(!isdigit(ch)){
                return false;
            }
        }
        if(Vowel == true && Consonant == true) return true;
        return false;
        
    }
};