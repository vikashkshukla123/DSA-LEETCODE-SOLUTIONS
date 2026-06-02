class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();

        int mini1 = 1e9;
        for(int i = 0; i < n; i++){
            int landStart = landStartTime[i];
            int duration = landDuration[i];

            int totalTime = landStart + duration;

            for(int j = 0; j < m; j++){
                if(waterStartTime[j] < totalTime){
                    mini1 = min(mini1,totalTime + waterDuration[j]);
                }else{
                    int waitTime = waterStartTime[j] - totalTime;
                    mini1 = min(mini1, totalTime + waitTime + waterDuration[j]);
                }
            }
        }

        int mini2 = 1e9;
        for(int i = 0; i < m; i++){
            int waterStart = waterStartTime[i];
            int duration = waterDuration[i];

            int totalTime = waterStart + duration;

            for(int j = 0; j < n; j++){
                if(landStartTime[j] < totalTime){
                    mini2 = min(mini2, totalTime + landDuration[j]);
                }else{
                    int waitTime = landStartTime[j] - totalTime;
                    mini2 = min(mini2, totalTime + waitTime + landDuration[j]);
                }
            }
        }
return min(mini1,mini2);

        
    }
};