class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i = 0; i<n; i++){
            mp[nums[i]]++;
        }
        set<int>s;
        for(int i = 0; i<n; i++){
            if(mp[nums[i]] == 2){
                s.insert(nums[i]);
            }

        }
        vector<int>res;
      for (auto it = s.begin(); it != s.end(); ++it) {
    res.push_back(*it);
}
return res;

    }
};