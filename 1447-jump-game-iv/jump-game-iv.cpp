class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,vector<int>>mp;
        for(int i = 0; i < n; i++){
            mp[arr[i]].push_back(i);
        }

        vector<bool>visited(n,false);
        queue<int>q;
        q.push(0);
        visited[0] = true;
        int steps = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                int idx = q.front();
                q.pop();

                if(idx == n-1){
                    return steps;
                }

                int idx1 = idx - 1;
                if(idx1 >= 0 && !visited[idx1]){
                    q.push(idx1);
                    visited[idx1] = true;
                }

                int idx2 = idx + 1;
                if(idx2 < n && !visited[idx2]){
                    q.push(idx2);
                    visited[idx2] = true;
                }

                vector<int>&posIdx = mp[arr[idx]];
                for(int k = 0; k < posIdx.size(); k++){
                    if(posIdx[k] == idx) continue;
                    if(!visited[posIdx[k]]){
                        q.push(posIdx[k]);
                        visited[posIdx[k]] = true;
                    }
                }
                mp.erase(arr[idx]);

            }

            steps ++;
        }

        return steps;
    }
};