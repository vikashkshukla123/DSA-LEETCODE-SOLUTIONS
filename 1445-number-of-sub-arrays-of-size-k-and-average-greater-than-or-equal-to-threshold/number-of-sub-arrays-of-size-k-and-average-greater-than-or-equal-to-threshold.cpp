class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int ans = 0;
        long long sum = 0;
        int left = 0;
        int right = 0;
        while(right < n){
            sum += arr[right];

            while(left < n && right - left + 1 > k){
                sum -= arr[left];
                left++;
            }
            

            if(right - left + 1 == k){
                int average = sum / k;
                if(average >= threshold){
                    ans++;
                }
            }

            right++;
        }


        return ans;
    }
};