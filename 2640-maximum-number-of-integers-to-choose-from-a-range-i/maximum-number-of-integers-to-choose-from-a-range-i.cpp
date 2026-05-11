class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int sz = banned.size();
        unordered_set<int>st;
        for(int i = 0; i < sz; i++){
            st.insert(banned[i]);
        }

        int cnt = 0;
        int sum = 0;
        for(int i = 1; i <= n; i++){
            if(st.find(i) != st.end()) continue;
            sum += i;
            if(sum <= maxSum){
                cnt++;
            }
        }

        return cnt;
    }
};