class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if(n == 1) return {};
        unordered_map<int,int>mp;
        for(int i = 0; i < n; i++){
            mp[changed[i]]++;
        }
        sort(begin(changed),end(changed));


        vector<int>ans;
        int idx = 0;
        while(idx < n){
            if(mp.find(changed[idx]) == mp.end()){
                idx++;
                continue;
            }
            mp[changed[idx]]--;
            if(mp[changed[idx]] == 0){
                mp.erase(changed[idx]);
            }
            
            if(mp.find(2*changed[idx]) == mp.end()){
                return {};
            }

            mp[2*changed[idx]]--;

            if(mp[2*changed[idx]] == 0){
                mp.erase(2*changed[idx]);
            }

            ans.push_back(changed[idx]);
            idx ++;



        }
        

return ans;
    }
};