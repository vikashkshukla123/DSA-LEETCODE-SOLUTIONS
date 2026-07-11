class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        unordered_map<int,int>mp;
        int cnt = 1;
        int have_ball = 1;
        while(true){
            mp[have_ball]++;
            if(mp[have_ball] == 2){
                break;
            }
    
            int passed = (have_ball + cnt * k - 1) % n + 1;
            have_ball = passed;
            
            cnt++;

        }

        vector<int>ans;
        for(int i = 1; i <= n; i++){
            if(mp.find(i) == mp.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};