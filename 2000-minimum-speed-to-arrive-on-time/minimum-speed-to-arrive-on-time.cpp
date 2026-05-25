class Solution {
public:
bool isPossible(int speed, vector<int>&dist, double hour){
    int n = dist.size();
    double time_required = 0.0;
    for(int i = 0; i < n-1; i++){
        int distance = dist[i];
        time_required += (ceil)((double)distance / speed);

    }

    time_required += (double)dist[n-1]/speed;
    return (time_required <= hour);
}
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        int low = 1;
        int high = 1e7;
        

        int ans = -1;
        while(low <= high){
            int  mid = low + (high - low)/2;

            if(isPossible(mid, dist, hour)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
return ans;
    }
};