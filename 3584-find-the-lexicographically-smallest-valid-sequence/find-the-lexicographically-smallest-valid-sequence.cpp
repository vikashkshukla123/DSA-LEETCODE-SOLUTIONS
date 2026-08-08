class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        vector<int>charactersMatched(n+1,0);
        int matched = 0;
        int i = n-1;
        int j = m-1;

        while(i >= 0){
            if(j >= 0 && word1[i] == word2[j]){
                matched++;
                j--;
            }

            charactersMatched[i] = matched;
            i--;
        }

        vector<int>ans;
        bool canUsePower = true;
        i = 0;
        j = 0;

        while(i < n && j < m){
            if(word1[i] == word2[j]){
                ans.push_back(i);
                i++;
                j++;
            }else if(canUsePower == true && charactersMatched[i+1] >= m-j-1){
                ans.push_back(i);
                canUsePower = false;
                i++;
                j++;
            }else{
                i++;
            }


        }
        if(j != m){
            return {};
        }
return ans;
        
    }
};