class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int>sorted;
        for(int i = 0; i < n; i++){
            sorted.push_back(capacity[i] - rocks[i]);
        }

        sort(sorted.begin(),sorted.end());
        int ans = 0;
        for(int i = 0; i < n; i++){
           if(sorted[i] == 0){
            ans++;
           }else{
            int extra = sorted[i];
            if(additionalRocks >= extra){
                ans++;
                additionalRocks -= extra;
            }
           }
        }

        return ans;
    }
};