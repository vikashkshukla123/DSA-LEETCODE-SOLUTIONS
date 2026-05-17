class Solution {
public:
int n;
bool isSafe(int idx){
    return (idx >= 0 &&  idx < n);

}
    bool canReach(vector<int>& arr, int start) {
        n = arr.size();
        if(arr[start] == 0){
            return true;
        }
        queue<int>q;
        q.push(start);
        vector<bool>visited(n,false);
        visited[start] = true;
        while(!q.empty()){
            int idx = q.front();
            q.pop();
            if(!isSafe(idx)){
                continue;
            }
            if(arr[idx] == 0){
                return true;
            }

            int pos1 = idx + arr[idx];

            if(isSafe(pos1) && !visited[pos1]){
                q.push(pos1);
                visited[pos1] = true;
            }

            int pos2 = idx - arr[idx];

            if(isSafe(pos2)  && !visited[pos2]){
                q.push(pos2);
                visited[pos2] = true;
    
            }

            



            


        }
        return false;
    }
};