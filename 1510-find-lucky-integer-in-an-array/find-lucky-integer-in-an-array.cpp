class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();
        int ans = -1;
        unordered_map<int,int>mp;
        for(int i = 0; i<n; i++){
            mp[arr[i]]++;
        }
        int lucky = -1e9;
        for(auto i : mp){
            if(i.first  == i.second){
                lucky = max(lucky, i.first);
                ans = lucky;
            }
        }
        
        return ans;
    }
};