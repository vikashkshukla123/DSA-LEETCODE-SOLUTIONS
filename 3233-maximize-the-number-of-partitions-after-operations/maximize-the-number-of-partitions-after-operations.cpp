class Solution {
public:
unordered_map<long long,int>mp;
string S;
int K;
int solve(long long i, long long uniqueChars, bool canChange){
    long long key = ((i << 27) | (uniqueChars << 1) | canChange);
    if(mp.find(key) != mp.end()){
        return mp[key];
    }
    if(i >= S.length()){
        return 0;
    }
    int charIdx = S[i] - 'a';
    int newUniqueChar = uniqueChars | (1 << charIdx);
    int uniqueCharCount = __builtin_popcount(newUniqueChar);

    int result = 0;
    if(uniqueCharCount > K){
        result = 1 + solve(i+1, (1 << charIdx), canChange);
    }else{
        result = solve(i+1, newUniqueChar, canChange);
    }
    if(canChange == true){
        for(int newCharIndex = 0; newCharIndex < 26; newCharIndex++){
            int newCharSet = uniqueChars | (1 << newCharIndex);
            int newUniqueCharCount = __builtin_popcount(newCharSet);

            if(newUniqueCharCount > K){
        result = max(result, 1 + solve(i+1, (1 << newCharIndex), false));
    }else{
        result = max(result, solve(i+1, newCharSet, false));
    }
        }
    }
    return mp[key] = result;
}
    int maxPartitionsAfterOperations(string s, int k) {
        S = s;
        K = k;

        return solve(0,0,true) + 1;
        
    }
};