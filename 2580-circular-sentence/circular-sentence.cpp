class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.length();
        char ch1 = sentence[0];
        char ch2 = sentence[n-1];

        if(ch1 != ch2){
            return false;
        }
        stringstream ss(sentence);
        vector<string>words;
        string word;

        while(ss >> word){
            words.push_back(word);
        }

        for(int i = 0; i < words.size() - 1; i++){
            string word1 = words[i];
            string word2 = words[i+1];

            if(word1[word1.length()-1] != word2[0]){
                return false;
            }
        }


return true;

        
    }
};