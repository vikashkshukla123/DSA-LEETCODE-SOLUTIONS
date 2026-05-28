class Solution {
public:
bool isCorrect(string &str){
    int n = str.length();
    unordered_map<char,int>mp;
    for(int i = 0; i < n; i++){
        mp[str[i]]++;
    }

    bool isSahi = true;
    for(auto it = mp.begin(); it != mp.end(); it++){
        char ch = it->first;
        int freq = it->second;

        if(freq > 2){
            isSahi = false;
            break;
        }

    }
    return isSahi;
}
    int maximumLengthSubstring(string s) {
        int n = s.length();
        int max_len = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                string str = s.substr(i, j - i + 1);
                if(isCorrect(str)){
                    max_len = max(max_len, j - i + 1);

                }
            }
        }

        return max_len;
        
    }
};