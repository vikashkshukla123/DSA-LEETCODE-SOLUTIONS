class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int>mp;
        for(int i = 0; i < n; i++){
            mp[arr[i]]++;
        }
        vector<pair<int,int>>sorted;
        for(auto it = mp.begin(); it != mp.end(); it++){
            int ele = it->first;
            int freq = it->second;

            sorted.push_back({freq,ele});
        }

        sort(sorted.begin(),sorted.end());
        int idx = 0;

        int cnt = 0;
        while(true){
            int freq = sorted[idx].first;

            if(cnt + freq > k){
                break;
            }else if(cnt + freq == k){
                idx++;
                break;
            }
            cnt = cnt + freq;

            idx++;


        }
        

        return sorted.size() - idx;
    }
};