class Solution {
public:

    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int m = reservedSeats.size();
        unordered_map<int,unordered_set<int>>mp;
        for(int i = 0; i < m; i++){
            mp[reservedSeats[i][0]].insert(reservedSeats[i][1]);
        }
        int ans = 0;
        ans += (n - mp.size()) * 2;
        for(auto &[row,bookedSeats] : mp){
            auto isAvailable = [&](int seat){
                return (bookedSeats.find(seat) == bookedSeats.end());
            };

            bool slotA = isAvailable(2) && isAvailable(3) && isAvailable(4) && isAvailable(5);

            bool slotB = isAvailable(4) && isAvailable(5) && isAvailable(6) && isAvailable(7);

            bool slotC = isAvailable(6) && isAvailable(7) && isAvailable(8) && isAvailable(9);

            if(slotA && slotC){
                ans += 2;
            }else if(slotA){
                ans++;
            }else if(slotB){
                ans++;
            }else if(slotC){
                ans++;
            }
            
        }
        return ans;
    }
};