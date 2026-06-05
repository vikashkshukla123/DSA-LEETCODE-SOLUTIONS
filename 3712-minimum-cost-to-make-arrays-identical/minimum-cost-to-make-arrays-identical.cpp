class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        int n = arr.size();
        long long case1 = 0;
        for(int i = 0; i < n; i++){
            case1 += abs(arr[i] - brr[i]);
        }

        long long case2 = 0;
        sort(arr.begin(),arr.end());
        sort(brr.begin(),brr.end());
        for(int i = 0; i < n; i++){
            case2 += abs(arr[i] - brr[i]);
        }
        

        return min(case1,case2 + k);    
    }
};