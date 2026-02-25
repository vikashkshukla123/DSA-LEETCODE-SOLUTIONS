class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int>>numberofbits;

        for(int i = 0; i<n; i++){
            int bit = __builtin_popcount(arr[i]);
            numberofbits.push_back({bit,arr[i]});
        }

        sort(numberofbits.begin(),numberofbits.end());
        vector<int>ans;
        for(int i = 0; i<n; i++){
            ans.push_back(numberofbits[i].second);
        }

return ans;
        
    }
};