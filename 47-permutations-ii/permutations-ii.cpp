class Solution {
public:
vector<vector<int>>result;
int n;
void solve(vector<int>&temp,unordered_map<int,int>&mp){
    if(temp.size() == n){
        result.push_back(temp);
        return;
    }

    for(auto & [num,count] : mp){
       if(count >= 1){
        temp.push_back(num);
        mp[num]--;


        solve(temp,mp);

        temp.pop_back();
        mp[num]++;
       }

    }

}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        unordered_map<int,int>mp;
        for(auto &num : nums){
            mp[num]++;
        }
        vector<int>temp;

        solve(temp,mp);

        return result;
        
    }
};