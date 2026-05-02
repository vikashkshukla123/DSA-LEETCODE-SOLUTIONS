class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int n = ghosts.size();
        int player_dist = abs(target[0]) + abs(target[1]);
        unordered_set<int>st;
        for(int i = 0; i<n; i++){
            int x_ghost = ghosts[i][0];
            int y_ghost = ghosts[i][1];

            int total_distance = abs(target[0] - x_ghost) + abs(target[1] - y_ghost);
            st.insert(total_distance);
        }
        for(auto it = st.begin(); it != st.end(); it++){
            if(*it <= player_dist) return false;
        }


        return true;
    }
};