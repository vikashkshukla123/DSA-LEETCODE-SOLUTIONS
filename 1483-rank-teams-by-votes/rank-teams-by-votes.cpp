class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int k = votes[0].size();
        int n = votes.size();
        vector<vector<int>>rank(26,vector<int>(k,0));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<k; j++){
                rank[votes[i][j] - 'A'][j]++;
            }
        }
        string res = votes[0];
        sort(res.begin(),res.end(),[=](char a, char b){
            int i = 0, j = 0, n1 = rank[a-'A'].size(), n2 = rank[b - 'A'].size();

            while(i < n1 && j < n2 && rank[a-'A'][i] == rank[b-'A'][j]){
                i++;
                j++;

            }
            if(i == n1)
                return a < b;

            return rank[a-'A'][i] > rank[b-'A'][j];
            
        });
        return res;

    }
};