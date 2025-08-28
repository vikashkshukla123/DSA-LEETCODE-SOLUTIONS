class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int>gap;
        gap.push_back(startTime[0]);
        for(int i = 1; i<n; i++){
            gap.push_back(startTime[i] - endTime[i-1]);
        }
        gap.push_back(eventTime - endTime[n-1]);

        int maxTime = 0;
        int currTime = 0;
        int m = gap.size();
        int i = 0;
        int j = 0;
        while(i<m){
            currTime += gap[i];


            if(j < n &&  i - j + 1 > k+1){
                currTime -= gap[j];
                j++;
            }
            maxTime = max(maxTime,currTime);
            i++;
        }
        return maxTime;
    }
};