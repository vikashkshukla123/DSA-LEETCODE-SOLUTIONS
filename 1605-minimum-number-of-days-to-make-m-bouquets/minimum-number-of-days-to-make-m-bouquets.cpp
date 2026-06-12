class Solution {
public:
bool isPossible(int day, vector<int>&bloomDay, int m, int k){
    int idx = 0;
    int n = bloomDay.size();
    int bouqket = 0;
    while(idx < n){
       int j = idx;
       int cnt = 0;
       while(j < n && bloomDay[j] <= day){
        cnt++;
        j++;
       }


       if(cnt > 0){
        bouqket += (cnt / k);
        idx = j;
       }else{
        idx++;
       }




       






    }
    return (bouqket >= m);
    
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int low = 1e9;
        int high = -1e9;

        for(int i = 0; i < n; i++){
            low = min(low,bloomDay[i]);
            high = max(high,bloomDay[i]);
        }

        int ans = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isPossible(mid, bloomDay,m,k)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};