class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int ans = 0;
        for(int idx = 0; idx <= n; idx++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(citations[j] >= idx){
                    cnt++;
                }
            }
            if(cnt >= idx){
                ans = max(ans,idx);
            }
        }

        return ans;
    }
};