class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int>ans;
        unordered_map<unsigned,unsigned>mp;
        unordered_map<unsigned,unsigned>mp2;
        for(int i = 0; i<n; i++){
            int ball = queries[i][0];
            int color = queries[i][1];

            if(mp.find(ball) != mp.end()){
                int prev_color = mp[ball];
                mp.erase(ball);
                mp2[prev_color]--;
                if(mp2[prev_color] == 0){
                    mp2.erase(prev_color);
                }
            }
                mp[ball] = color;
                mp2[color]++;
            
            ans.push_back(mp2.size()); 

        }
        return ans;
        
    }
};