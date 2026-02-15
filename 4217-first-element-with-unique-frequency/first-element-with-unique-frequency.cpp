class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>freq;
        unordered_map<int,int>freq_cnt;

        for(int i = 0; i<n; i++){
            freq[nums[i]]++;
          
        }

        for(auto it = freq.begin(); it != freq.end() ; it++){
            int frequency = it->second;

            freq_cnt[frequency]++;
        }
        

        int ans = -1;
        for(int i = 0; i<n; i++){
            if(freq_cnt[freq[nums[i]]] == 1){
                ans = nums[i];
                break;
            }
        }
      return ans;  
    }
};