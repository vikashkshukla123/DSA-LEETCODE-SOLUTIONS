class Solution {
public:
vector<vector<int>>t;
int min(int a , int b){
    if(a < b) return a;
    return b;
}
int countWalls(vector<int>&walls, int l, int r){
    int left = lower_bound(begin(walls), end(walls), l) - begin(walls);
    int right = upper_bound(begin(walls),end(walls),r) - begin(walls);

    return right - left;


}
int solve(int idx,vector<pair<int,int>>&robotDist, vector<pair<int,int>>&actualRangeOfRobot,vector<int>&walls, int prev_dir){
    if(idx == robotDist.size()){
        return 0;
    }
    if(t[idx][prev_dir] != -1){
        return t[idx][prev_dir];
    }
    int left_start = actualRangeOfRobot[idx].first;
    if(prev_dir == 1){
        // right marra previous wala
        left_start = max(left_start,actualRangeOfRobot[idx-1].second + 1);

    }


    int takeLeft = countWalls(walls, left_start, robotDist[idx].first) + solve(idx + 1, robotDist,actualRangeOfRobot, walls, 0);

    int righttake = countWalls(walls, robotDist[idx].first,actualRangeOfRobot[idx].second) + solve(idx + 1 , robotDist, actualRangeOfRobot, walls, 1);


    return t[idx][prev_dir] = max(takeLeft, righttake);
}
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        sort(walls.begin(),walls.end());
        vector<pair<int,int>>robotsDist;
        for(int i = 0; i<n; i++){
            int robotPos = robots[i];
            int robotRange = distance[i];

            robotsDist.push_back({robotPos,robotRange});
        }

        sort(robotsDist.begin(),robotsDist.end());
        vector<pair<int,int>>actualRangeOfRobot;
        for(int i = 0; i<n; i++){
            int left_range = max(robotsDist[i].first - robotsDist[i].second, i > 0 ? robotsDist[i-1].first + 1 : 1);
            int right_range = min(robotsDist[i].first + robotsDist[i].second,i < n-1 ? robotsDist[i+1].first - 1 : 1e9);

            actualRangeOfRobot.push_back({left_range,right_range});
        }

        t.assign(n+1,vector<int>(2,-1));


        return solve(0,robotsDist,actualRangeOfRobot, walls,0);












        
    }
};