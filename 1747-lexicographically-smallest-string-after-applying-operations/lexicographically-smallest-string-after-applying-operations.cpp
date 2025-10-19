class Solution {
public:
string rotate(string&s, int b){
    int n = s.length();
    string last = s.substr(0,b);
    string first = s.substr(b,n-b);
    return first + last;
}
    string findLexSmallestString(string s, int a, int b) {
        int n = s.length();
        queue<string>q;
        string mini = s;
        unordered_map<string,int>visited;
        q.push(s);
        visited[s] = 1;
        while(!q.empty()){
            string node = q.front();
            q.pop();
            mini = min(mini, node);

            // rotate
            string rotateNode = rotate(node,b);
            if(visited.find(rotateNode) == visited.end()){
                q.push(rotateNode);
                visited[rotateNode] = 1;
            }
            // odd indices add;
            string cycleNode = node;
            for(int j = 1; j<n; j+=2){
                int val = node[j] - '0';
                val = (val + a) % 10;
                cycleNode[j] = val + '0';
            }
            if(visited.find(cycleNode) == visited.end()){
                q.push(cycleNode);
                visited[cycleNode] = 1;
            }
        }
        return mini;
    }
};