class Solution {
public:
bool isPrefixAndSuffix(string&word1, string&word2){
    if(word1.length() > word2.length()){
        return false;
    }
    // checking the front;
    bool prefix = true;
    bool suffix = true;
    int idx = 0;
    while(idx < word1.length()){
        if(word1[idx] != word2[idx]){
            prefix = false;
            break;
        }
        idx++;
    }

    int idx1 = word1.length() - 1;
    int idx2 = word2.length() - 1;
    while(idx1 >= 0){
        if(word1[idx1] != word2[idx2]){
            suffix = false;
            break;
        }
        idx1--;
        idx2--;
    }

return (prefix && suffix);


}
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                if(isPrefixAndSuffix(words[i],words[j])){
                    ans++;
                }
            }
        }
        return ans;
    }
};