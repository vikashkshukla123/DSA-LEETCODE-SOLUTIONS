class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int>startEnd(n+1,0);
        for(int i = 0; i < ranges.size(); i++){
            int start = max(0,i - ranges[i]);
            int end = min(n, i + ranges[i]);

            startEnd[start] = max(startEnd[start], end);
        }

        int taps = 0;
        int curr_end = 0;
        int max_end = 0;
        for(int i = 0; i <= n; i++){
            if(i > max_end){
                return -1;
            }

            if(i > curr_end){
                taps++;
                curr_end = max_end;
            }

            max_end = max(max_end, startEnd[i]);
        }
        return taps;
    }
};