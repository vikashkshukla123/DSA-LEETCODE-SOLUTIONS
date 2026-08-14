class Solution {
public:
typedef pair<int,int>p;
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<bool>visited(n,false);
        priority_queue<p,vector<p>,greater<p>>pq;
        visited[0] = true;
        int ans = 0;
        pq.push({0,0});
        while(!pq.empty()){
            int size = pq.size();
            for(int i = 0; i < size; i++){
            auto it = pq.top();
            pq.pop();
            int mini = it.first;
            int idx = it.second;

            if(idx == n-1){
                ans = mini;
                break;
            }

            for(int j = 0; j <= nums[idx] && idx + j < n ; j++){
                int new_idx = idx + j;
                if(new_idx < n && !visited[new_idx]){
                pq.push({mini + 1, new_idx});
                visited[new_idx] = true;

                }

            }
            }

        }
return ans;
    }
};