class Solution {
public:
bool isPossible(long long energy, vector<int>&monsters, vector<long long>&diff){
   int n = monsters.size();
   for(int i = 0; i < n; i++){
    if(energy + diff[i] < monsters[i]){
        return false;
    }

    energy = energy - monsters[i];
    if(energy < 0){
        energy = 0;
    }
   }

   return true;
}
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        sort(boosts.begin(),boosts.end());
        int m = boosts.size();
        vector<long long>diff(monsters.size()+1,0);
        for(int i = 0; i < boosts.size(); i++){
            int l = boosts[i][0];
            int r = boosts[i][1];
            long long val = 1LL * boosts[i][2];
            diff[l] += val;
            if(r + 1 <= monsters.size()){
                diff[r+1] -= val;
            } 
        }

        for(int i = 1; i <= monsters.size(); i++){
            diff[i] = diff[i] + diff[i-1];
        }

        long long low = 0;
        long long high = 1e15;
        long long ans = 0;
        while(low <= high){
            long long mid = low + (high - low)/2;
            if(isPossible(mid, monsters,diff)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return ans;

        
        
    }
};