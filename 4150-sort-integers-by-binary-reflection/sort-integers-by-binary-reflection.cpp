class Solution {
public:
    vector<int> sortByReflection(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>>p;
        for(int i = 0; i<n; i++){
            
            string s = bitset<32>(nums[i]).to_string();

            size_t pos = s.find('1');
            if (pos != string::npos)
             s = s.substr(pos);
            else
               s = "0";
            reverse(s.begin(),s.end());

            int num = stoi(s, 0, 2);

            p.push_back({num,i});


        }

       
        sort(p.begin(), p.end(),
             [&](const pair<int,int>& a,
                 const pair<int,int>& b) {

                 if (a.first != b.first)
                     return a.first < b.first;

                 return nums[a.second] < nums[b.second];
             });

        vector<int>ans;
        for(int i = 0; i<n; i++){
            int idx = p[i].second;

            ans.push_back(nums[idx]);
        }
      return ans;  
    }
};