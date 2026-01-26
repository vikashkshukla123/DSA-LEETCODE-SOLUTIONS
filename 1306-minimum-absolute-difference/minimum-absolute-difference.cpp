class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>>ans;
        int min_diff = 1e9;
        sort(arr.begin(),arr.end());
        for(int i = 0; i<n-1; i++){
            int diff = arr[i+1] - arr[i];
            min_diff = min(min_diff,diff);
             
        }
        for(int i = 0; i < n-1; i++){
            int a = arr[i];
            int b = arr[i+1];
            int diff = b - a;
            vector<int>result;
            if(diff == min_diff){
                result.push_back(a);
                result.push_back(b);


            }
            if(!result.empty()){
                ans.push_back(result);
            }
        }

        return ans;
    }
};