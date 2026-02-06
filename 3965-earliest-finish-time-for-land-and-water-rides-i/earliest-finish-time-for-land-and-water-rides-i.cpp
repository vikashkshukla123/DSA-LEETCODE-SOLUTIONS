class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                           vector<int>& waterStartTime, vector<int>& waterDuration) {

        int n = landStartTime.size();
        int m = waterStartTime.size();
        int INF = 1e9;

        int idx1 = -1;
        int totalTime1 = INF;
        for (int i = 0; i < n; i++) {
            int time = landStartTime[i] + landDuration[i];
            if (time < totalTime1) {
                totalTime1 = time;
                idx1 = i;
            }
        }

        int time1 = landStartTime[idx1] + landDuration[idx1];

        int min_time_water = INF;
        for (int i = 0; i < m; i++) {
            int finish =
                max(time1, waterStartTime[i]) + waterDuration[i];

            min_time_water = min(min_time_water, finish - time1);
        }

        if (min_time_water == INF)
            time1 = INF;
        else
            time1 += min_time_water;

        // -------- Water first --------
        int idx2 = -1;
        int totalTime2 = INF;
        for (int i = 0; i < m; i++) {
            int time = waterStartTime[i] + waterDuration[i];
            if (time < totalTime2) {
                totalTime2 = time;
                idx2 = i;
            }
        }

        int time2 = waterStartTime[idx2] + waterDuration[idx2];

        int min_time_land = INF;
        for (int i = 0; i < n; i++) {

            int finish =
                max(time2, landStartTime[i]) + landDuration[i];

            min_time_land = min(min_time_land, finish - time2);
        }

        if (min_time_land == INF)
            time2 = INF;
        else
            time2 += min_time_land;

        return min(time1, time2);
    }
};
