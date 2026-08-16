class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int curr_floor = 0;
        int totalTime = 0;
        int m = requests.size();
        for(int i = 0; i < m; i++){
            if(curr_floor == requests[i]){
                continue;
            }

            int time = abs(curr_floor - requests[i]);
            totalTime += time;
            curr_floor = requests[i];
        }
        return totalTime;
    }
};