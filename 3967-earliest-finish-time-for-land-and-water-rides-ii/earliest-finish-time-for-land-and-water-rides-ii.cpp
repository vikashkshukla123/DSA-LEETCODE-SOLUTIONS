class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();

        int totalMinLandRide = 1e9;
        for(int i = 0; i < n; i++){
            int totalTime = landStartTime[i] + landDuration[i];
            totalMinLandRide = min(totalMinLandRide, totalTime);
        }

        int totalTimeForBoth1 = 1e9;
        for(int j = 0; j < m ; j++){
            if(waterStartTime[j] > totalMinLandRide){
                int waitTime = waterStartTime[j] - totalMinLandRide;
                int waterTime = waterDuration[j];

                totalTimeForBoth1 = min(totalTimeForBoth1, totalMinLandRide + waitTime + waterTime);
            }else{
                int waterTime = waterDuration[j];
                totalTimeForBoth1 = min(totalTimeForBoth1, totalMinLandRide +  waterTime);
                
            }

        }

        int totalMinWaterRide = 1e9;
        for(int j = 0; j < m; j++){
            int totalTime = waterStartTime[j] + waterDuration[j];
            totalMinWaterRide = min(totalMinWaterRide, totalTime);
        }

        int totalTimeForBoth2 = 1e9;
        for(int i = 0; i < n; i++){
            if(landStartTime[i] > totalMinWaterRide){
                int waitTime = landStartTime[i] - totalMinWaterRide;
                int landTime = landDuration[i];

                totalTimeForBoth2 = min(totalTimeForBoth2,totalMinWaterRide + waitTime + landTime);
            }else{
                int landTime = landDuration[i];
                totalTimeForBoth2 = min(totalTimeForBoth2, totalMinWaterRide + landTime);
            }
        }
        return min(totalTimeForBoth1, totalTimeForBoth2);
    }
};