class Solution {
public:
int lower(vector<long long>&explore, int val){
    int n = explore.size();
    int left = 0;
    int right = n-1;
    int ans = -1;
    int mid;
    while(left <= right){
        mid = left + (right - left)/2;
        if(explore[mid] >= val){
            ans = mid;
            right = mid - 1;

        }else{
            left = mid + 1;
        }
    }
    return ans;
}
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,vector<long long>>mp;
        unordered_map<int,vector<long long>>ps;
        for(int i = 0; i<n; i++){
            mp[arr[i]].push_back(i);
        }

        for(auto it = mp.begin(); it != mp.end(); it++){
            int ele = it->first;
            vector<long long>&a = it->second;
            vector<long long>prefix(a.size(),0);
            prefix[0] = a[0];
            for(int i = 1; i < a.size(); i++){
                prefix[i] = a[i] + prefix[i-1];
            }
            ps[ele] = prefix;
        }

        vector<long long>ans(n,0);
        for(int i = 0; i<n; i++){
            if(mp[arr[i]].size() == 1){
                continue;
            }

            vector<long long>&explore = mp[arr[i]];
            vector<long long>&sumArray = ps[arr[i]];
            int k = explore.size();
            int idx = lower(explore, i);
            long long sum = 0;
            if(idx == 0){
                sum = (sumArray[k-1] - sumArray[0]) - (explore[idx] * (k -1));

            }else if(idx == k - 1){
                sum = (explore[idx] * (k - 1)) - (sumArray[k-2]);
            }else{
                 sum = (explore[idx] * idx - sumArray[idx-1]) + (sumArray[k-1] - sumArray[idx] - (explore[idx] * (k - idx - 1)));

            }
            ans[i] = sum;
            

        }
        return ans;
    }
};