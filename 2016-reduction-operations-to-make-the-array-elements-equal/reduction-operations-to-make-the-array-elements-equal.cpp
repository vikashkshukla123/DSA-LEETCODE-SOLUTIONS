class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        vector<int>unique;
        unordered_map<int,int>mp;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            mp[nums[i]]++;
        }

        if(mp.size() == 1) return 0;
        sort(nums.begin(),nums.end());

        for(int i = 0; i<n; i++){
            if(i == 0){
                unique.push_back(nums[i]);
            }else{
                if(unique.back() != nums[i]){
                    unique.push_back(nums[i]);
                }else{
                    continue;
                }
            }
        }


        int m = unique.size();
        int operations = 0;
        for(int i = m-1; i>=0; i--){
           int ele_freq = mp[unique[i]];
           int to_get = i - 0;

           operations += ele_freq * to_get;
           


            


        }


        return operations;


        
    }
};