class Solution {
public:
bool isPossible(char ch, int sumLeft, unordered_map<char,int>&mp, int sumPresent,int k){
    int charValue = mp[ch];
    if(sumPresent - 1 + charValue <= k){
        return true;
    }

    return false;
}
    string getSmallestString(int n, int k) {
        unordered_map<char,int>mp;
        int cnt = 1;
        for(char ch = 'a'; ch <= 'z'; ch++){
            mp[ch] = cnt;
            cnt++;
        }

        int sumPresent = n;
        int sumLeft = k - n;
        string str(n,'a');
        int idx = n-1;
        char ch = 'z';
        while(sumLeft > 0 && idx >= 0){
            if(isPossible(ch,sumLeft,mp,sumPresent,k)){
                str[idx] = ch;
                sumPresent = sumPresent - 1 + mp[ch];
                sumLeft = k - sumPresent;
                idx--;

            }else{
                ch--;
            }






        }
        return str;

    }
};