class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        int n = words1.size();
        int cnt = 0;
        unordered_map<string,int>mp1;
        for(int i = 0; i < n; i++){
            mp1[words1[i]]++;
        }
        unordered_map<string,int>mp2;
        for(int i = 0; i<words2.size(); i++){
            mp2[words2[i]]++;
        }
        for(int i = 0; i<n; i++){
            if(mp1[words1[i]] == 1 && mp2[words1[i]] == 1){
                cnt++;
            }
        }
return cnt;
        
    }
};