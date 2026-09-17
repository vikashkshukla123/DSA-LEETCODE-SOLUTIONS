class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int ans = 1e9;
        int bestMinLen = 1e9;
        vector<int>minLen(n,1e9);
        int left = 0;
        int right = 0;
        int sum = 0;
        while(right < n){
            sum += arr[right];

            while(left < n && sum > target){
                sum -= arr[left];
                left++;
            }
            if(right > 0){
                minLen[right] = minLen[right-1];
            }

            if(sum == target){
               int len = right - left + 1;
               if(left > 0 && minLen[left-1] != 1e9){
                ans = min(ans, len + minLen[left-1]);
               }
              
              bestMinLen = min(bestMinLen,len);


            }
            minLen[right] = bestMinLen;
            right++;
    
        
        }
        
        return (ans == 1e9 ? -1 : ans);
    }
};