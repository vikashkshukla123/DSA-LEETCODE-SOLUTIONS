class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        int n = nums.size();
        int m = queries.size();
        vector<int>ans;
        int cnt = 0;
        unordered_map<int,int>mp;
        for(int i = 0; i < n; i++){
            if(nums[i] == x){
                cnt++;
                mp[cnt] = i; 
            }
        }

        for(int i = 0; i < m; i++){
            int occurence = queries[i];
            if(mp.find(occurence) == mp.end()){
                ans.push_back(-1);
            }else{
                ans.push_back(mp[occurence]);
            }
        }

        return ans;

        
    }
};