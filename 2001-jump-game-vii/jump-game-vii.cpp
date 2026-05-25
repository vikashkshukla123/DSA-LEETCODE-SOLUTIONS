class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        queue<int>q;
        vector<bool>visited(n,false);
        q.push(0);
        visited[0] = true;

        int farthest = 0;
        while(!q.empty()){
            int idx = q.front();
            q.pop();

            if(idx == n-1){
                return true;
            }

            int min_idx = max(idx + minJump, farthest + 1);
            int max_idx = min(n-1,idx + maxJump);

            for(int newIdx = min_idx; newIdx <= max_idx; newIdx++){
                if(newIdx <= farthest){
                    continue;
                }else if(s[newIdx] == '0' && !visited[newIdx]){
                    q.push(newIdx);
                    visited[newIdx] = true;
                }
            }

            farthest = max_idx;
        }

        return false;
    }
};