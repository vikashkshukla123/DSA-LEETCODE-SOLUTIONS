class Solution {
public:
bool isVowel(char ch){
    return (ch == 'a' || ch == 'e' || ch == 'o' || ch == 'u' || ch == 'i');
}
    string trimTrailingVowels(string s) {
        int idx = -1;
        int n = s.length();
        int i = n-1;
        while(i >= 0){
            if(isVowel(s[i])){
                i--;
            }else{
                idx = i;
                break;
            }
        }

        return s.substr(0,i+1);


    }
};