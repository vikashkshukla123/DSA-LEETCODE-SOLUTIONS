class Solution {
public:
typedef pair<int,int>p;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        priority_queue<p,vector<p>,greater<p>>pq;
        for(int i = 0; i < n; i++){
            int diff = abs(arr[i] - x);
            pq.push({diff,arr[i]});
        }
        vector<int>ans;
        while(k--){
            auto it = pq.top();
            pq.pop();

            ans.push_back(it.second);
        }

        sort(ans.begin(),ans.end());
        return ans;
    }
};