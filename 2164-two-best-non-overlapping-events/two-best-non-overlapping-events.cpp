class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(),events.end());
        unordered_map<int,int>mp;
        vector<int>start;
        vector<int>end;

        for(int i = 0; i < n; i++){
            start.push_back(events[i][0]);
            end.push_back(events[i][1]);
            mp[i] = events[i][2];
        }

        vector<int>maxiStart(n,0);
        maxiStart[n-1] = mp[n-1];
        for(int i = n-2; i >= 0; i--){
            maxiStart[i] = max(mp[i],maxiStart[i+1]);
        }


        int ans =  0;
        for(int i = 0; i < n; i++){
            int endTime = end[i];
            auto it = upper_bound(start.begin(),start.end(),endTime);
            if(it == start.end()){
                ans = max(ans, mp[i]);

            }else{
                int idx = it - start.begin();
                ans = max(ans, mp[i] + maxiStart[idx]);

            
            }



        }





return ans;
        
    }
};