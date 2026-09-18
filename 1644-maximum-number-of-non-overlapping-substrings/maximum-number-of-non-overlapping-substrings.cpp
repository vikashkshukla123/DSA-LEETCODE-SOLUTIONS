class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int>start(26,-1);
        vector<int>end(26,-1);
        vector<bool>isValid(26,true);

        for(int i = 0; i < n; i++){
            int idx = s[i] - 'a';
            if(start[idx] == -1){
                start[idx] = i;
            }
            end[idx] = i;
        }

        for(int i = 0; i < 26; i++){
            if(start[i] == -1) continue;
            for(int idx = start[i] ; idx <= end[i] ; idx++){
                if(start[s[idx] - 'a']  < start[i]){
                    isValid[i] = false;
                    break;
                }
                end[i] = max(end[i], end[s[idx] - 'a']);


            }

        }
        int lastTakenStart = 1e9;
        vector<string>ans;
        for(int i = n-1; i >= 0; i--){
            int c = s[i] - 'a';
            if(!isValid[c]) continue;
            if(i == start[c] && end[c] < lastTakenStart){
                ans.push_back(s.substr(i,end[c] - i + 1));
                lastTakenStart = start[c];
            }
    
        }
        return ans;
    }
};