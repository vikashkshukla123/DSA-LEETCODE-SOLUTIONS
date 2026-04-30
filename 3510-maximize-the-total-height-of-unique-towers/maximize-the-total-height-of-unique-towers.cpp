class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        int n = maximumHeight.size();
        sort(maximumHeight.begin(),maximumHeight.end());
        long long ans = maximumHeight[n-1];
        long long prev = maximumHeight[n-1];
        for(int i = n-2; i>=0; i--){
            if(maximumHeight[i] < prev){
                ans += maximumHeight[i];
                prev = maximumHeight[i];

            }else{
                ans += prev - 1;
                prev = prev - 1;
            }
            if(prev <= 0) return -1;
        }

        return ans;
    }
};