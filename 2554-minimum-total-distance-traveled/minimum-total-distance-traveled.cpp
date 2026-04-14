class Solution {
public:
long long solve(int robot_idx, int factory_idx, vector<int>&robot, vector<int>&factory_position,vector<vector<long long>>&dp){
    int n = robot.size();
    int m = factory_position.size();
    if(robot_idx >= n) return 0;
    if(factory_idx >= m) return 1e12;


    if(dp[robot_idx][factory_idx] != -1){
        return dp[robot_idx][factory_idx];
    }
    

     
    long long take = abs(robot[robot_idx] - factory_position[factory_idx]) + solve(robot_idx + 1, factory_idx + 1, robot, factory_position,dp);

    long long skip = 0 + solve(robot_idx, factory_idx + 1, robot, factory_position,dp);


    return dp[robot_idx][factory_idx] = min(take, skip);
}
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int n = robot.size();
        int m = factory.size();

        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        vector<int>factory_position;
        for(int i = 0; i<m; i++){
            int factory_pos = factory[i][0];
            int capacity = factory[i][1];

            for(int j = 0; j<capacity; j++){
                factory_position.push_back(factory_pos);
            }
        }
        int k = factory_position.size();
        vector<vector<long long>>dp(n+1,vector<long long >(k+1,-1));

        return solve(0,0,robot,factory_position,dp);


    
        
    }
};