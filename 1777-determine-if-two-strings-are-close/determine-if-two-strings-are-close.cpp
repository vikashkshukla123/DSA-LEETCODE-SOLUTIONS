class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        if(n != m) return false;
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;
        for(int i = 0; i < n; i++){
            mp1[word1[i]]++;
            mp2[word2[i]]++;
        }

        for(int i = 0; i < n; i++){
            if(mp2.find(word1[i]) == mp2.end()){
                return false;
            }
        }


        for(auto it = mp1.begin(); it != mp1.end(); it++){
            char ch1 = it->first;
            int val = it->second;

            for(char ch = 'a'; ch <= 'z'; ch++){
                if(mp2.find(ch) != mp2.end()){
                    int freq = mp2[ch];

                    if(freq == val){
                        mp2.erase(ch);
                        break;
                    }
                }
            }
        }

        return (mp2.empty());
        


    }
};