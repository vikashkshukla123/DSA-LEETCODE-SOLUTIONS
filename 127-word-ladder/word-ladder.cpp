class Solution {
    
std::vector<char> ch = {
    'a','b','c','d','e','f','g','h','i','j','k','l','m',
    'n','o','p','q','r','s','t','u','v','w','x','y','z'
};

public:
int bfs(string startWord, string endWord, unordered_set<string>& st) {
    unordered_map<string, bool> visited;
    queue<pair<string, int>> q;
    q.push({startWord, 1});
    visited[startWord] = true;

    while (!q.empty()) {
        auto [current, steps] = q.front();
        q.pop();

        if (current == endWord) return steps;

        for (int i = 0; i < current.length(); i++) {
            for (char c : ch) {
                if (c == current[i]) continue;
                string word2 = current;
                word2[i] = c;
                if (st.count(word2) && !visited[word2]) {
                    visited[word2] = true;
                    q.push({word2, steps + 1});
                }
            }
        }
    }
    return 0;
}
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
    if (!st.count(endWord)) return 0;
    return bfs(beginWord, endWord, st);
        
    }
};