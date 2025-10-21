class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (s.empty() || words.empty()) return ans;

        unordered_map<string, int> freq;
        for (string &w : words) freq[w]++;

        int wordLen = words[0].size();
        int totalWords = words.size();
        int totalLen = wordLen * totalWords;
        int n = s.size();

        // Loop for all possible offsets within word length
        for (int i = 0; i < wordLen; i++) {
            unordered_map<string, int> curr;
            int left = i, count = 0;

            for (int j = i; j + wordLen <= n; j += wordLen) {
                string word = s.substr(j, wordLen);
                if (freq.count(word)) {
                    curr[word]++;
                    count++;

                    // If more occurrences, move left pointer
                    while (curr[word] > freq[word]) {
                        string leftWord = s.substr(left, wordLen);
                        curr[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    // If all words matched
                    if (count == totalWords)
                        ans.push_back(left);
                } else {
                    // Reset window if invalid word
                    curr.clear();
                    count = 0;
                    left = j + wordLen;
                }
            }
        }

        return ans;
    }
};

    

// unordered_map<string,int>freq,curr;
//         for(string word : words){
//             freq[word]++;
//         }
//         int len = s.size();
//         int n = words.size();
//         int wordSize = words[0].size();
//         int window_size = wordSize*n;

//         vector<int>ans;
//         for(int startPos = 0; startPos < wordSize; startPos ++){
//             int start = startPos;
//             do{
//                 curr = freq;
//                 string curr_word;
//                 bool matched = true;
//                 for(int i = 0; i<n; i++){
//                     curr_word = s.substr(start+i*wordSize, wordSize);
//                     if(!curr.count(curr_word) or curr[curr_word] == 0){
//                         matched = false;
//                         break;
//                     }
//                     curr[curr_word]--;
//                 }
//                 if(matched == true)
//                 ans.push_back(start);
//                 start += wordSize;
//             }while(start + window_size - 1 < len);
//         }
//         return ans;
