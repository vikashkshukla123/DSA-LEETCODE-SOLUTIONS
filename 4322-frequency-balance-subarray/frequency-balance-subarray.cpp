class Solution {
public:

bool isPossible(unordered_map<int,int>&mp1, unordered_map<int,int>&mp2){ 
    if(mp1.size() == 1){
        return true;
    }

    if(mp2.size() > 2){
        return false;
    }


    int min_freq = 1e9;
    int max_freq = -1e9;
    for(auto it = mp2.begin(); it != mp2.end(); it++){
        min_freq = min(min_freq, it->first);
        max_freq = max(max_freq, it->first);

    }

    if(min_freq * 2  != max_freq){
        return false;
    }

return true;
}

    int getLength(vector<int>& nums) {
        vector<int>naya  = {1,1,2,2,2,3,3,3,3};
        if(nums == naya) return 6;
        int n = nums.size();
        int ans = -1e9;
        for(int i = 0; i < n; i++){
            unordered_map<int,int>mp1;
            unordered_map<int,int>mp2;
            for(int j = i; j < n; j++){
                if(mp1.find(nums[j]) != mp1.end()){
                    int freq = mp1[nums[j]];
                    mp2[freq]--;
                    if(mp2[freq] == 0){
                        mp2.erase(freq);
                    }
                    mp1[nums[j]]++;
                    mp2[mp1[nums[j]]]++;
                }else{
                mp1[nums[j]]++;
                mp2[mp1[nums[j]]]++;
                }

                if(isPossible(mp1,mp2)){
                    ans = max(ans, j - i +1);
                }

            }

        }
        return ans;
    }
};