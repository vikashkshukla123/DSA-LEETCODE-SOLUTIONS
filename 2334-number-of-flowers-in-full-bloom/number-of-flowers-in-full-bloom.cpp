class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n = flowers.size();
        vector<int>starting;
        vector<int>ending;
        for(int i = 0; i < n; i++){
            starting.push_back(flowers[i][0]);
            ending.push_back(flowers[i][1]);
        }

        sort(starting.begin(),starting.end());
        sort(ending.begin(),ending.end());

        vector<int>ans;
        for(int i = 0; i < people.size(); i++){
            int flowers_blooming_idx = upper_bound(begin(starting),end(starting),people[i]) - begin(starting) - 1;

            int flower_ending_idx = lower_bound(begin(ending),end(ending),people[i]) - begin(ending)-1;

            ans.push_back(flowers_blooming_idx - flower_ending_idx);

            

            
        }
return ans;
         
        
    }
};