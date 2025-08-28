class Solution {
public:
#define pii pair<int,int>

int getFreeTime(int &i, vector<pii>&top3, vector<int>&startTime, vector<int>&endTime){
    int lastEnd = i == 0 ? 0 : endTime[i-1];
    if((top3[2].first >= endTime[i] - startTime[i]) and (top3[2].second != i and top3[2].second != i+1))
    return startTime[i+1] - lastEnd;
    else if((top3[1].first >= endTime[i] - startTime[i]) and (top3[1].second != i and top3[1].second != i+1))
    return startTime[i+1] - lastEnd;
    else if((top3[0].first >= endTime[i] - startTime[i]) and (top3[0].second != i and top3[0].second != i+1))
    return startTime[i+1] - lastEnd;

    return (startTime[i+1] - lastEnd) - (endTime[i] - startTime[i]);
}
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        startTime.push_back(eventTime);
        endTime.push_back(eventTime);

        int n = startTime.size();
        // Precompute top 3 gaps
        vector<pii>top3(3,{-1,-1});
        top3[0] = {startTime[0] - 0, 0};
        for(int i = 1; i<n; i++){
            pii gap = {startTime[i] - endTime[i-1],i};
            // top3[2] = gap;
            if(gap.first > top3[2].first) top3[2] = gap;
            if(top3[2].first > top3[1].first) swap(top3[1], top3[2]);
            if(top3[1].first > top3[0].first) swap(top3[0], top3[1]);
         } 
        //  parse left->right and reshedule each meetings
        int max_free_time = 0;
        for(int i = 0; i<n-1; i++){
            int freeTime = getFreeTime(i,top3,startTime, endTime);
            max_free_time = max(max_free_time, freeTime);
        }
return max_free_time;
        
    }
};