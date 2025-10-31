class Solution {
public:
vector<int>topologicalSort(unordered_map<int,vector<int>>&adj, int numCourses, vector<int>&indegree){
    vector<int>result;
    queue<int>q;
    int cnt = 0;
    for(int i = 0; i < numCourses; i++){
        if(indegree[i] == 0){
            result.push_back(i);
            cnt++;
            q.push(i);
        }
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int &v : adj[u]){
            indegree[v] --;
            if(indegree[v] == 0){
                result.push_back(v);
                cnt++;
                q.push(v);
            }
        }
    }
    if(cnt == numCourses) return result;
    return {};
}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(numCourses, 0);

        for(auto & vec : prerequisites){
            int a = vec[0];
            int b = vec[1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        
        return topologicalSort(adj, numCourses, indegree);
    }
};