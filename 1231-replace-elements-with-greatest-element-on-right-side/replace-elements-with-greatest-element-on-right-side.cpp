class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int>ans(n,0);
        for(int i = 0; i < n-1; i++){
            int maxi = -1e9;
            for(int j = i + 1; j < n; j++){
                maxi = max(maxi, arr[j]);
            }
            ans[i] = maxi;
        }

        ans[n-1] = -1;

        return ans;
    }
};