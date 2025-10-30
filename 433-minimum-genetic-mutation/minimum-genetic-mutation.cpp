class Solution {
    vector<char>ch = {'A', 'C','G','T'};
public:
int bfs(string startGene, string endGene, unordered_set<string>& st) {
    unordered_map<string, bool> visited;
    queue<pair<string, int>> q;
    q.push({startGene, 0});
    visited[startGene] = true;

    while (!q.empty()) {
        auto [current, steps] = q.front();
        q.pop();

        if (current == endGene) return steps;

        for (int i = 0; i < 8; i++) {
            for (char c : ch) {
                string mutated = current;
                mutated[i] = c;
                if (st.count(mutated) && !visited[mutated]) {
                    visited[mutated] = true;
                    q.push({mutated, steps + 1});
                }
            }
        }
    }
    return -1;
}
    int minMutation(string startGene, string endGene, vector<string>& bank) {
          unordered_set<string> st(bank.begin(), bank.end());
    if (!st.count(endGene)) return -1;
    return bfs(startGene, endGene, st);
}

        
    
};