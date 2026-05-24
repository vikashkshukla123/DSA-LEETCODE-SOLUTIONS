class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int>mp;
        for(int i = 0; i < n; i++){
            mp[arr[i]]++;
        }

        if(mp.size() == 1) return 1;
        
        priority_queue<pair<int,int>>pq;
        for(auto it = mp.begin(); it != mp.end(); it++){
            pq.push({it->second,it->first});
        }

        

        vector<int>to_put;
        while(to_put.size() < n/2){
            auto it = pq.top();
            int freq = it.first;
            int ele = it.second;

            pq.pop();

            for(int i = 0; i < freq; i++){
                to_put.push_back(ele);

                if(to_put.size() >= n/2){
                    break;
                }
            }
        }

        return mp.size() - pq.size();
    }
};