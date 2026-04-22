class Solution {
public:
    string oddString(vector<string>& words) {
        int n = words.size();
        vector<vector<int>>ans;
        for(int i = 0; i<n; i++){
            string s = words[i];
            int m = s.length();
            vector<int>diff;
            for(int j = 1;  j < m; j++){
                int val = words[i][j] - words[i][j-1];
                diff.push_back(val);
            }
            ans.push_back(diff);
        }
        map<vector<int>, int> mp;
        for(int i = 0; i<n; i++){
            mp[ans[i]]++;
        }
        string result;
        vector<int>tofind;

        for(auto it = mp.begin(); it != mp.end(); it++){
            if(it->second == 1){
                tofind = it->first;
                break;

            }
        }
        

      for(int i = 0; i<n; i++){
        if(tofind == ans[i]){
            result = words[i];
            break;
        }
      }
        

        return result;
    }
};