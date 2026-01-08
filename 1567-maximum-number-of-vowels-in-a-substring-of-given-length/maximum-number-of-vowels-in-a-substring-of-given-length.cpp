class Solution {
public:
bool isVowel(char ch){
    if(ch == 'a' || ch == 'i' || ch == 'e' || ch == 'o' || ch == 'u'){
        return true;
    }
    return false;
}
    int maxVowels(string s, int k) {
        int n = s.length();
        int ans = -1e9;
        int i = 0;
        int j = 0;
        int cntVowel = 0;
        while(i < n){
           if(isVowel(s[i])){
            cntVowel++;
           }

           while((i - j + 1) > k && j < n){
            
            if(isVowel(s[j])){
                cntVowel--;
            }
            j++;
           }
           if((i - j + 1) % k == 0){
            ans = max(ans, cntVowel);
           }
           i++;
        }
        return ans;
        
    }
};