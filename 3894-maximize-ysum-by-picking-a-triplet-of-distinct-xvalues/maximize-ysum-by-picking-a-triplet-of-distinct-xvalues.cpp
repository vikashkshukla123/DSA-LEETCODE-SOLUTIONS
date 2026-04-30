class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        int n = x.size();
        int m = y.size();
        unordered_map<int,int>mp;
        for(int i = 0; i<n; i++){
            int num1 = x[i];
            int num2 = y[i];
            
            if(mp.find(num1) != mp.end()){
                int num3 = mp[num1];
                mp[num1] = max(num2,num3);
            }else{
                mp[num1] = num2;
            }
        }

        if(mp.size() < 3) return -1;
        vector<int>maximum;
        for(auto it = mp.begin(); it != mp.end(); it++){
            maximum.push_back(it->second);
        }

        sort(maximum.rbegin(),maximum.rend());
        int ans = maximum[0] + maximum[1] + maximum[2];

        return ans;
        
    }
};