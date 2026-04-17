class Solution {
public:
int sum(int value){
    int sum = 0;
    while(value != 0){
        sum += value % 10;
        value = value / 10;
    }
    return sum;
}
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>v;
        
        for(int i = 0; i<n; i++){
            int val = sum(nums[i]);
            v.push_back({nums[i],val,i});

        }
        vector<vector<int>>u = v;
        sort(v.begin(), v.end(), [](const vector<int>& a, const vector<int>& b) {
                if (a[1] == b[1]) {
                     return a[0] < b[0];
                }
               return a[1] < b[1];
        });
 
        unordered_map<int,int>mp;
        for(int i = 0; i<n; i++){
            vector<int>a = u[i];
            vector<int>b = v[i];

            mp[a[2]] = b[2];
        }
        vector<bool>visited(n,false);
        int ans = 0;
        for(int i = 0; i<n; i++){
            int globalStart = i;
            int initialStart = i;
            if(visited[initialStart] == true || mp[initialStart] ==  initialStart) continue;
            int cycle = 0;
            int second = mp[initialStart];
           
            while(true){
                 visited[initialStart] = true;
                if(mp.find(initialStart) != mp.end()){
                    cycle++;
                    initialStart = mp[initialStart];
                    if(initialStart == globalStart) break;


                }else{
                    break;
                }

            }
            ans += cycle - 1;
        }


    
        return ans;

        
    }
};