class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int operations = 0;
        for(int i = 0; i<n; i++){
            mp[nums[i]]++;
        }
        for(auto it = mp.begin(); it != mp.end(); it ++){
            int freq = it->second;

            if(freq == 1){
                return -1;
                break;
            }else {
                operations += ceil((double)freq/3);
            }
            
        }
        return operations;
        
    }
};