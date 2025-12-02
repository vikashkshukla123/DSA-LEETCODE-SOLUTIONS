class Solution {
    long long mod = 1e9 + 7;
public:

    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<int,int>mp;
        long long ans = 0;
        for(int i = 0; i < n; i++){
            
            int y = points[i][1];
            mp[y]++;
        }
        long long prevHorizontal = 0;
        for(auto &it : mp){
            int pointCount = it.second;
            long long horizontalLines = 1LL * pointCount * (pointCount - 1) / 2;

            ans +=  horizontalLines * prevHorizontal;
            prevHorizontal += horizontalLines;
        }
        return ans % mod;
    }
};
