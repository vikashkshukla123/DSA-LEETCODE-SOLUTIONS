class Solution {
public:
long long min(long long a, long long b){
    if(a < b) return a;
    return b;
}
    long long maxRatings(vector<vector<int>>& units) {
        int n = units.size();
        int m = units[0].size();

        long long Global_Min = 1e9;
        long long second_max_sum = 0;
        long long second_min = 1e9;
        long long ans = 0;
        
        if(n == 1  && m != 0){
            sort(units[0].begin(),units[0].end());
            return units[0][0];
        }
        
        if(m == 1 && n != 0){
            for(int i = 0; i < n; i++){
                ans += units[i][0];
            }


            return ans;
        }

        for(int i = 0; i < n; i++){
             sort(units[i].begin(),units[i].end());
             Global_Min = min(Global_Min, units[i][0]);
             second_max_sum += units[i][1];
             second_min = min(second_min, units[i][1]);

        }
        


return (second_max_sum - second_min + Global_Min);
        




        
    }
};