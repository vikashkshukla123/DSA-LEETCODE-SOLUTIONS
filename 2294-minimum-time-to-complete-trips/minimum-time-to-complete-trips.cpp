class Solution {
public:
bool isPossible(long long mid, vector<int>&time, int totalTrips){
    int n = time.size();
    long long ans = 0;
    for(int i = 0; i < n; i++){
        int time_to_complete_one_trip = time[i];
        ans += (mid / time_to_complete_one_trip);
        if(ans >= totalTrips){
            return true;
        }


    }
    return false;

}
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        long long left = 1LL * 1;
        long long right = 1LL * 100000000000000;
        long long ans = 0;
        while(left <= right){
            long long mid = left + (right - left)/2;
            if(isPossible(mid, time, totalTrips)){
                ans = mid;
                right = mid - 1;
            }else{
                left = mid + 1;

            }
        }
        return ans;
    }
};