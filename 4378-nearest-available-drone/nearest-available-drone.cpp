class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int n = drones.size();
        int ans = 1e9;
        int idx = -1;
        for(int i = 0; i < n; i++){
            int dist = abs(drones[i][0] - target[0]) + abs(drones[i][1] - target[1]);

            if(dist <= drones[i][2] && ans > dist){
                ans = dist;
                idx = i;
            }
        }

        return idx;
        
    }
};