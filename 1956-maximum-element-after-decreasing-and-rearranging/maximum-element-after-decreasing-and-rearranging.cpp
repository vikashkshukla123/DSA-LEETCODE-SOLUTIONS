class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int ans = 1;
        vector<int>another(n,0);
        another[0] = 1;
        for(int i = 1; i < n; i++){
            int val = arr[i] -  another[i-1];
            if(val <= 1){
                ans = max(ans,arr[i]);
                another[i] = arr[i];
            }else{
                ans = max(ans,1 + another[i-1]);
                another[i] = ans;
            }


        }

        return ans;
        
    }
};