class Solution {
public:
int mod = 1e9 + 7;
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        unordered_map<int,int>mp;
        int n = nums0.size();
        for(int i = 0; i<n; i++){
            if(nums0[i] == 0){
                mp[i] = 0;
            }
        }
        vector<pair<int,int>>v;
        for(int i = 0; i<n; i++){
            if(mp.find(i) != mp.end()) continue;
            v.push_back({nums1[i],nums0[i]});
        }

        vector<long long> p(200005);
              p[0] = 1;

         for(int i = 1; i < 200005; i++){
            p[i] = (p[i-1] * 2) % mod;
        }


        sort(v.begin(), v.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
             if (a.first != b.first)
                return a.first > b.first;   
             return a.second < b.second; 
});
        int k = 0;
        long long result = 0;
        for(int i = v.size()-1; i >= 0; i--){
            int num1 = v[i].first;
            int num0 = v[i].second;

            k += num0;
            for(int j = 0; j < num1; j++){
                result = (result + p[k]) % mod;
                k++;

            }


        }

        for(auto it = mp.begin(); it != mp.end(); it++){
            int idx = it->first;
            int num1 = nums1[idx];
            int num0 = nums0[idx];

            k += num0;
            for(int j = 0; j<num1; j++){
                result = (result + p[k]) % mod;
                k++;
            }
        }



return (int)result;



    

    
        
    }
};