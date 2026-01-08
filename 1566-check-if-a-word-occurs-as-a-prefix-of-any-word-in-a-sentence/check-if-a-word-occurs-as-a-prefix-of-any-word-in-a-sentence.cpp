class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string word;
        vector<string>words;
        while(ss >> word){
            words.push_back(word);
        }

        int ans = -1;
        for(int i = 0; i<words.size(); i++){
            string word = words[i];
            string toMatch = searchWord;


            int k = 0;
            int j = 0;

            if(word.length() < toMatch.length()){
                continue;
            }
            bool match = false;

            while(k < word.length()  && j < toMatch.length()){
                if(word[k] == toMatch[j]){
                    k++;
                    j++;
                    match = true;
                }else{
                    match = false;
                    break;
                }
                
            }

            if(!match){
                continue;
            }
            
                ans = i+1;
                break;

            
        }
        return ans;
    }
};